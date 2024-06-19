#include "Shooting.h"
#include "BiathlonTarget.h"
#include "RifleTarget.h"
#include "TargetDrawing.h" 

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Shooting::Shooting() : shooter(nullptr) {}

void Shooting::start() {
    setupShooter();
    menu();
}

void Shooting::setupShooter() {
    string shooterName;
    cout << "Enter shooter's name: ";
    cin >> shooterName;
    cout << endl;
    shooter = new Shooter(shooterName);
    cout << "Welcome, " << shooter -> getName() << "!" << endl;
}

void Shooting::menu() {
    cout << "Choose shooting event:" << endl;
    cout << endl;
    cout << "1. Biathlon" << endl;
    cout << "2. Rifle" << endl;

    cout << endl << "Enter your choice (1 or 2): ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        biathlonShooting();
        break;
    case 2:
        rifleShooting();
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void Shooting::biathlonShooting() {
    vector<BiathlonTarget> biathlonTargets;
    int arr[5]{ -25, -15, -5, 5, 15 };

    for (int i = 0; i < numTargetsBiathlon; i++) {
        biathlonTargets.emplace_back(arr[i], 0);
    }

    cout << endl << "Biathlon Shooting: " << endl;
    int resBiathlon = 0;
    vector<int> biathlonResults;

    for (int i = 0; i < shotsBiathlon; i++) {
        double x, y;
        bool validInput = false;

        while (!validInput) {
            cout << "Coordinate " << i + 1 << ": ";
            string input;
            getline(cin, input);
            stringstream ss(input);

            if (ss >> x >> y) {
                validInput = true;
            } else {
                cout << "Please enter valid coordinates." << endl;
            }
        }

        int points = -1;

        for (auto& target : biathlonTargets) {
            points = shooter -> shot(target, x, y);
            if (points > 0) {
                biathlonResults.push_back(points);
                break;
            }
        }

        TargetDrawing::draw(arr[i], 0, 4, x, y);
        

        if (points != -1) {
            resBiathlon += points;
            cout << "Points: " << points << endl;
            cout << endl;
        } else {
            cout << "Cannot shoot anymore." << endl;
        }
    }
    TargetDrawing::displayScreen();
    displayResults(biathlonResults);
    displayStatistics();
}

void Shooting::rifleShooting() {
    RifleTarget rifleTarget(0, 0);

    cout << endl << "Rifle Shooting: " << endl;
    int resRifle = 0;
    vector<int> rifleResults;

    for (int i = 0; i < shotsRifle; i++) {
        double x, y;
        bool validInput = false;

        while (!validInput) {
            cout << "Coordinate " << i + 1 << ": ";
            string input;
            getline(cin, input);
            stringstream ss(input);

            if (ss >> x >> y) {
                validInput = true;
            } else {
                cout << "Please enter valid coordinates." << endl;
            }
        }
        int points = shooter->shot(rifleTarget, x, y);

        if (points != -1) {
            resRifle += points;
            cout << "Points: " << points << endl;
            rifleResults.push_back(points);
        } else {
            cout << "Cannot shoot anymore." << endl;
        }
    }
    TargetDrawing::draw(0, 0, 10, 0, 0);
    TargetDrawing::displayScreen();
    displayResults(rifleResults);
    displayStatistics();
}