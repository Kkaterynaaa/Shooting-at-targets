#pragma once

#ifndef SHOOTER_H
#define SHOOTER_H

#include "AbstractTarget.h"

class Shooter {
    public:
        int shot(AbstractTarget& target, double x, double y);
};

#endif