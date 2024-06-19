#pragma once

#ifndef RIFLETARGET_H
#define RIFLETARGET_H

#include "AbstractTarget.h"

class RifleTarget: public AbstractTarget {
    public:
        RifleTarget(double x, double y);

        bool canShoot() const override;
        int shot(double x, double y) override;
        void coordinatesOfTarget(double& x, double& y) const override;

        static int distanceToPoints(double distance);

    private:
        double x1, y1;
        int maxShots;
        static const int shotsRifle = 5;
        static const int maxDistanceRifle = 10;
};

#endif