#pragma once

#ifndef ABSTRACTTARGET_H
#define ABSTRACTTARGET_H

class AbstractTarget {
    public:
        virtual bool canShoot() const = 0;
        virtual int shot(double x, double y) = 0;
        virtual void coordinatesOfTarget(double& x, double& y) const = 0;

        virtual ~AbstractTarget() = default;
};

#endif
