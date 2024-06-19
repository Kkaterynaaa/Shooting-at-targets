#pragma once

#ifndef SHOOTER_H
#define SHOOTER_H

#include "AbstractTarget.h"

#include <string>

using namespace std;

class Shooter {
    public:
        Shooter(const string& name);

        const string& getName() const;

        int shot(AbstractTarget& target, double x, double y);

        double biathlonHitPercentage() const;
        double rifleHitPercentage() const;

    private:
        string name;
        int biathlonShots;
        int biathlonHits;
        int rifleShots;
        int rifleHits;
};

#endif
