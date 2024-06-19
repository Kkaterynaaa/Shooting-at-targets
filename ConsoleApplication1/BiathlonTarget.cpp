#include "BiathlonTarget.h"

#include <cmath>

double sqr(double x) {
    return x * x;
}

BiathlonTarget::BiathlonTarget(double x, double y, double radius, int successPoints):
    x1(x), y1(y), flag(true), radius(radius), successPoints(successPoints) {}

bool BiathlonTarget::canShoot() const {
    return flag;
}

int BiathlonTarget::shot(double x, double y) {
    if (flag) {

        int distance = sqr(x - x1) + sqr(y - y1);
        if (distance < radius * radius) {
            flag = false;
            return successPoints;
        }
    }
    return 0;
}

void BiathlonTarget::coordinatesOfTarget(double& x, double& y) const {
    x = x1;
    y = y1;
}
