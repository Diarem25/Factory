#ifndef VARIABLESTORAGE_H
#define VARIABLESTORAGE_H

#include <vector>
#include <string>

class VariableStorage {
    std::vector<int> partStock;
    int maxCapacity;

public:
    VariableStorage(int maxCapacity, int numParts = 6);
    bool consumePart(int partIndex);
    std::string getTrafficLight(int partIndex) const;
    void displayStatus() const;
    bool canProduce(int partIndex) const;
    void replenishPart(int partIndex, int amount);
};

#endif
