#include "Controller.h"
#include <iostream>
#include <cstdlib>  // for rand()

Controller::Controller() : factory1(5, 960), factory2(8, 160) {}

void Controller::runDay() {
    dailyDemand = rand() % 41 + 230;  // Random demand between 230 and 270
    std::cout << "Market demand for the day: " << dailyDemand << " products\n";

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(40, 48); // define the range

    int a = generateRandomBinomial();
    int b = generateRandomBinomial();
    int c = generateRandomBinomial();
    int d = generateRandomBinomial();
    int e = dailyDemand - a -b-c-d;

    std::cout << "The demand of the different products are" << std::endl << "1:" << a << std::endl << "2:" << b << std::endl << "3:" << c << std::endl << "4:" << d << std::endl << "5:" << e << std::endl;
    

    totalProduced = factory1.runProduction(dailyDemand);

    if (totalProduced < dailyDemand) {
        int remainingDemand = dailyDemand - totalProduced;
        for (int productType = 1; productType <= 5; productType++) {
            factory2.setProductTypeForAllLines(productType);
            int producedByFactory2 = factory2.runProduction(remainingDemand);
            totalProduced += producedByFactory2;
            remainingDemand -= producedByFactory2;

            if (remainingDemand <= 0) break;
        }
    }

    std::cout << "Total products produced: " << totalProduced << "\n";

    // Replenish stock after production
    replenishStock();

    // Display status of storage after replenishing
    factory1.displayStatus();
    factory2.displayStatus();

    // Show performance review
    double points = performanceReview();
    std::cout << "Performance Points for the Day: " << points << "\n";
}

// Replenish stock for the factories when the traffic light turns yellow
void Controller::replenishStock() {
    // For Factory 1 (Base storage)
    const BaseStorage& baseStorage = factory1.getStorage();
    if (baseStorage.getTrafficLight() == "Yellow") {
        const_cast<BaseStorage&>(baseStorage).replenishBase(50);  // Replenish the base stock to bring it back up
        std::cout << "Replenished base stock in Factory 1.\n";
    }

    // For Factory 2 (Variable storage)
    const VariableStorage& varStorage = factory2.getStorage();
    for (int i = 0; i < 6; ++i) {
        if (varStorage.getTrafficLight(i) == "Yellow") {
            const_cast<VariableStorage&>(varStorage).replenishPart(i, 50);  // Replenish 50 units for each part that's yellow
            std::cout << "Replenished part " << i << " stock in Factory 2.\n";
        }
    }
}

int generateRandomBinomial() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::binomial_distribution<> d(48, 40.0 / 48.0);

    return d(gen);
}

// Calculate performance based on traffic lights, quota met, and leftover products
double Controller::performanceReview() const {
    double points = 0;

    // Check traffic light performance for Factory 1
    std::string baseTraffic = factory1.getStorage().getTrafficLight();
    if (baseTraffic == "Green") {
        points += 1;
    } else if (baseTraffic == "Yellow") {
        points += 0.5;
    }

    // Check traffic light performance for Factory 2
    for (int i = 0; i < 6; i++) {
        std::string partTraffic = factory2.getStorage().getTrafficLight(i);
        if (partTraffic == "Green") {
            points += 1;
        } else if (partTraffic == "Yellow") {
            points += 0.5;
        }
    }

    // Add 3 points if the demand quota is met
    if (totalProduced >= dailyDemand) {
        points += 3;
    }

    // Subtract 0.1 points for each leftover product if overproduction occurs
    if (totalProduced > dailyDemand) {
        int leftover = totalProduced - dailyDemand;
        points -= leftover * 0.1;
    }

    return points;
}
