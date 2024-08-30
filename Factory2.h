#ifndef FACTORY2_H
#define FACTORY2_H

#include <vector>
#include "VariableAssemblyLine.h"
#include "VariableStorage.h"

class Factory2 {
    std::vector<VariableAssemblyLine> lines;
    VariableStorage storage;

public:
    Factory2(int numLines, int storageCapacity, int numParts = 6);
    void setProductTypeForAllLines(int productType);
    int runProduction(int remainingDemand);
    void displayStatus() const;
    const VariableStorage& getStorage() const;  // Getter method for storage
};

#endif
