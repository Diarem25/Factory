#include "Factory2.h"

Factory2::Factory2(int numLines, int storageCapacity, int numParts) : storage(storageCapacity, numParts) {
    for (int i = 0; i < numLines; i++) {
        lines.emplace_back(storage);
    }
}

void Factory2::setProductTypeForAllLines(int productType) {
    for (auto& line : lines) {
        line.setProductType(productType);
    }
}

int Factory2::runProduction(int remainingDemand) {
    int totalProduced = 0;
    for (auto& line : lines) {
        totalProduced += line.produce();
        if (totalProduced >= remainingDemand) break;
    }
    return totalProduced;
}

void Factory2::displayStatus() const {
    storage.displayStatus();
}

const VariableStorage& Factory2::getStorage() const {
    return storage;
}
