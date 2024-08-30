#include <iostream>
#include <vector>
#include "Controller.h"
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed random number generator

    Controller controller;

    bool keepRunning = true;
    while (keepRunning) {
        controller.runDay();
        std::cout << "Run another day? (1: yes, 0: no): ";
        std::cin >> keepRunning;
    }

    return 0;
}
