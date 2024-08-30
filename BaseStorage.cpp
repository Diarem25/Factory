#include "BaseStorage.h"
#include <iostream>
#include <algorithm>  // for std::min

BaseStorage::BaseStorage(int maxCapacity) : baseStock(maxCapacity), maxCapacity(maxCapacity) {}

bool BaseStorage::consumeBase() {
    if (baseStock > 0) {
        baseStock--;
        return true;
    }
    return false;
}

std::string BaseStorage::getTrafficLight() const {
    if (baseStock >= 50) return "Green";
    if (baseStock >= 25) return "Yellow";
    return "Red";
}

void BaseStorage::displayStatus() const {
    std::cout << "Base Stock: " << baseStock << " (" << getTrafficLight() << ")\n";
}

bool BaseStorage::canProduce() const {
    return baseStock > 0;
}

void BaseStorage::replenishBase(int amount) {
    baseStock = std::min(baseStock + amount, maxCapacity);
}
