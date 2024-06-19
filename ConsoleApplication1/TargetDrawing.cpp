#include "TargetDrawing.h"
#include <cmath>

using namespace std;

const int TargetDrawing::CONSOLE_WIDTH = 60;
const int TargetDrawing::CONSOLE_HEIGHT = 30;

vector<vector<char>> TargetDrawing::screen(TargetDrawing::CONSOLE_HEIGHT, vector<char>(TargetDrawing::CONSOLE_WIDTH, ' '));

void TargetDrawing::draw(int centerX, int centerY, int radius, int shotX, int shotY) {
    for (int y = -TargetDrawing::CONSOLE_HEIGHT / 2; y <= TargetDrawing::CONSOLE_HEIGHT / 2; ++y) {
        for (int x = -TargetDrawing::CONSOLE_WIDTH / 2; x <= TargetDrawing::CONSOLE_WIDTH / 2; ++x) {
            int screenY = y + TargetDrawing::CONSOLE_HEIGHT / 2;
            int screenX = x + TargetDrawing::CONSOLE_WIDTH / 2;

            if (screenY >= 0 && screenY < TargetDrawing::CONSOLE_HEIGHT && screenX >= 0 && screenX < TargetDrawing::CONSOLE_WIDTH) {
                if (x == shotX && y == shotY) {
                    TargetDrawing::screen[screenY][screenX] = '0';
                }
                else if (pow(x - centerX, 2) + pow(y - centerY, 2) <= pow(radius, 2)) {
                    TargetDrawing::screen[screenY][screenX] = '*';
                }
            }
        }
    }
}

void TargetDrawing::displayScreen() {
    for (int y = 0; y < TargetDrawing::CONSOLE_HEIGHT; ++y) {
        for (int x = 0; x < TargetDrawing::CONSOLE_WIDTH; ++x) {
            cout << TargetDrawing::screen[y][x] << " ";
        }
        cout << endl;
    }
}

void TargetDrawing::clearScreen() {
    TargetDrawing::screen.assign(TargetDrawing::CONSOLE_HEIGHT, vector<char>(TargetDrawing::CONSOLE_WIDTH, ' '));
}
