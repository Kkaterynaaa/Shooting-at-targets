#pragma once

#ifndef TARGETDRAWING_H
#define TARGETDRAWING_H

using namespace std;

#include <iostream>
#include <vector>

class TargetDrawing {
    private:
        static const int CONSOLE_WIDTH;
        static const int CONSOLE_HEIGHT;
        static vector<vector<char>> screen;

    public:
        static void draw(int centerX, int centerY, int radius, int shotX, int shotY);
        static void displayScreen();
        static void clearScreen();
};

#endif

