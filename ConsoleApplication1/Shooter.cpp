#include "Shooter.h"

int Shooter::shot(AbstractTarget& target, double x, double y) {
    if (target.canShoot()) {
        return target.shot(x, y);
    } else {
        return -1;
    }
}
