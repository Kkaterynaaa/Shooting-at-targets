#include "Shooting.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int distanceTargetsBiathlon = 10;
const int numTargetsBiathlon = 5;
const int shotsBiathlon = 5;
const int shotsRifle = 10;

void Shooting::biathlon() {
    Shooter shooter;
    vector<BiathlonTarget> biathlonTargets;

    for (int i = 0; i < numTargetsBiathlon; i++) {
        biathlonTargets.emplace_back(distanceTargetsBiathlon * (i + 1), 0);
    }

    cout << "Biathlon Shooting: " << endl;
    int resBiathlon = 0;

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
            points = shooter.shot(target, x, y);
            if (points > 0) {
                break;
            }
        }

        if (points != -1) {
            resBiathlon += points;
            cout << "Points: " << points << endl;
        } else {
            cout << "Cannot shoot anymore." << endl;
        }
    }
    cout << endl << "Result biathlon shooting: " << resBiathlon << endl;
}

void Shooting::rifle() {
    Shooter shooter;
    RifleTarget rifleTarget(0, 0);

    cout << "Rifle Shooting: " << endl;
    int resRifle = 0;

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

        int points = shooter.shot(rifleTarget, x, y);

        if (points != -1) {
            resRifle += points;
            cout << "Points: " << points << endl;
        } else {
            cout << "Cannot shoot anymore." << endl;
        }
    }
    cout << endl << "Result rifle shooting: " << resRifle << endl;
}
