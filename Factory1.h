#ifndef FACTORY1_H
#define FACTORY1_H

#include <vector>
#include "FixedAssemblyLine.h"
#include "BaseStorage.h"

class Factory1 {
    std::vector<FixedAssemblyLine> lines;
    BaseStorage storage;

public:
    Factory1(int numLines, int storageCapacity);
    int runProduction(int demand);
    void displayStatus() const;
    const BaseStorage& getStorage() const;  // Getter method for storage
};

#endif
