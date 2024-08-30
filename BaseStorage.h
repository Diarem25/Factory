#ifndef BASESTORAGE_H
#define BASESTORAGE_H

#include <string>

class BaseStorage {
    int baseStock;
    int maxCapacity;

public:
    BaseStorage(int maxCapacity);
    bool consumeBase();
    std::string getTrafficLight() const;
    void displayStatus() const;
    bool canProduce() const;
    void replenishBase(int amount);
};

#endif
