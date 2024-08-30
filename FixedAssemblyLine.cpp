#include "FixedAssemblyLine.h"

FixedAssemblyLine::FixedAssemblyLine(BaseStorage& storage) : dailyProduction(48), storage(storage) {}

int FixedAssemblyLine::produce() {
    int produced = 0;
    for (int i = 0; i < dailyProduction; i++) {
        if (storage.consumeBase()) produced++;
        else break;
    }
    return produced;
}
