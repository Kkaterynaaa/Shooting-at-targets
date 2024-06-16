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
        int distanceToPoints(double points);

    private:
        double x1, y1;
        int maxShots;
       
};

#endif

