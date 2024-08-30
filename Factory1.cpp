#include "Factory1.h"

Factory1::Factory1(int numLines, int storageCapacity) : storage(storageCapacity) {
    for (int i = 0; i < numLines; i++) {
        lines.emplace_back(storage);
    }
}

int Factory1::runProduction(int demand) {
    int totalProduced = 0;
    for (auto& line : lines) {
        totalProduced += line.produce();
        if (totalProduced >= demand) break;
    }
    return totalProduced;
}

void Factory1::displayStatus() const {
    storage.displayStatus();
}

const BaseStorage& Factory1::getStorage() const {
    return storage;
}
