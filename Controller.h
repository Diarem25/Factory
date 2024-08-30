#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <random>

#include "Factory1.h"
#include "Factory2.h"

class Controller {
    Factory1 factory1;
    Factory2 factory2;

    int dailyDemand;
    int totalProduced;

public:
    Controller();
    void runDay();
    void replenishStock();
    int generateRandomBinomial();
    double performanceReview() const;
};

#endif
