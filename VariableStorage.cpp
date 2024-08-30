#include "VariableStorage.h"
#include <iostream>
#include <algorithm>  // for std::min

VariableStorage::VariableStorage(int maxCapacity, int numParts) : maxCapacity(maxCapacity) {
    partStock.resize(numParts, maxCapacity);
}

bool VariableStorage::consumePart(int partIndex) {
    if (partStock[partIndex] > 0) {
        partStock[partIndex]--;
        return true;
    }
    return false;
}

std::string VariableStorage::getTrafficLight(int partIndex) const {
    int stockLevel = partStock[partIndex];

    if (stockLevel >= 50) return "Green";
    if (stockLevel >= 25) return "Yellow";
    return "Red";
}

void VariableStorage::displayStatus() const {
    for (size_t i = 0; i < partStock.size(); i++) {
        std::cout << "Part " << i << " Stock: " << partStock[i] << " (" << getTrafficLight(i) << ")\n";
    }
}

bool VariableStorage::canProduce(int partIndex) const {
    return partStock[partIndex] > 0;
}

void VariableStorage::replenishPart(int partIndex, int amount) {
    partStock[partIndex] = std::min(partStock[partIndex] + amount, maxCapacity);
}
