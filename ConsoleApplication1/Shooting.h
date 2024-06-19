#pragma once

#ifndef SHOOTING_H
#define SHOOTING_H

#include "BiathlonTarget.h"
#include "RifleTarget.h"
#include "Shooter.h"

#include <iostream>
#include <vector>

using namespace std;

class Shooting {
    public:
        Shooting();

        void start();

        void setupShooter();
        void menu();

        void biathlonShooting();
        void rifleShooting();

    private:
        Shooter* shooter;
         const int distanceTargets = 10;
         const int shotsBiathlon = 5;
         const int shotsRifle = 5;
         const int numTargetsBiathlon = 5;

        void displayResults(const vector<int>& results) {
            cout << "Results shooting:";
            for (int result : results) {
                cout << " " << result;
            }
            cout << endl;
        }

        void displayStatistics() {
            cout << "Biathlon Hit Percentage: " << shooter->biathlonHitPercentage() << "%" << endl;
            cout << "Rifle Hit Percentage: " << shooter->rifleHitPercentage() << "%" << endl;
        }
};

#endif

