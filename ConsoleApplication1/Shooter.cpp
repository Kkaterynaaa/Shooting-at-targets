#include "Shooter.h"
#include "BiathlonTarget.h" 
#include "RifleTarget.h"  

using namespace std;

Shooter::Shooter(const string& name):
    name(name), biathlonShots(0), biathlonHits(0), rifleShots(0), rifleHits(0) {
}

const string& Shooter::getName() const {
    return name;
}

int Shooter::shot(AbstractTarget& target, double x, double y) {
    if (target.canShoot()) {
        int points = target.shot(x, y);
        if (dynamic_cast<BiathlonTarget*>(&target)) {
            biathlonShots++;
            if (points > 0) biathlonHits++;
        } else if (dynamic_cast<RifleTarget*>(&target)) {
            rifleShots++;
            if (points > 0) rifleHits++;
        }
        return points;
    } else {
        return -1;
    }
}

double Shooter::biathlonHitPercentage() const {
    if (biathlonShots > 0) {
        return static_cast<double>(biathlonHits) / biathlonShots * 100.0;
    }
    return 0.0;
}

double Shooter::rifleHitPercentage() const {
    if (rifleShots > 0) {
        return static_cast<double>(rifleHits) * 100.0 / rifleShots;
    }
    return 0.0;
}
