#pragma once

#ifndef BIATHLONTARGET_H
#define BIATHLONTARGET_H

#include "AbstractTarget.h"

class BiathlonTarget: public AbstractTarget {
    public:
        BiathlonTarget(double x, double y, double radius = 4, int successPoints = 1);

        bool canShoot() const override;
        int shot(double x, double y) override;
        void coordinatesOfTarget(double& x, double& y) const override;

    private:
        double x1, y1, radius;
        int successPoints;
        bool flag;
};

#endif