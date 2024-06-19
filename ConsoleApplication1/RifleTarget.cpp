#include "RifleTarget.h"

#include <stdexcept>
#include <cmath>

using namespace std;

static double sqr(double x) {
    return x * x;
}

RifleTarget::RifleTarget(double x, double y):
    x1(x), y1(y), maxShots(shotsRifle) {
}

bool RifleTarget::canShoot() const {
    return maxShots > 0;
}

int RifleTarget::shot(double x, double y) {
    if (!canShoot()) {
        throw invalid_argument("Cannot shoot anymore!");
    }
    maxShots--;
    double distance = sqrt(sqr(x - x1) + sqr(y - y1));
    return distanceToPoints(distance);
}

int RifleTarget::distanceToPoints(double distance) {
    if (distance >= 0 && distance <= maxDistanceRifle) {
        if (distance <= 1) return 10;
        else if (distance < 2) return 9;
        else if (distance < 3) return 8;
        else if (distance < 4) return 7;
        else if (distance < 5) return 6;
        else if (distance < 6) return 5;
        else if (distance < 7) return 4;
        else if (distance < 8) return 3;
        else if (distance < 9) return 2;
        else return 1;
    }
    return 0;
}

void RifleTarget::coordinatesOfTarget(double& x, double& y) const {
    x = x1;
    y = y1;
}
