#include "VariableAssemblyLine.h"

VariableAssemblyLine::VariableAssemblyLine(VariableStorage& storage) : productType(0), dailyProduction(48), storage(storage) {}

void VariableAssemblyLine::setProductType(int pType) {
    productType = pType;
}

int VariableAssemblyLine::produce() {
    int produced = 0;
    for (int i = 0; i < dailyProduction; i++) {
        if (storage.consumePart(productType)) produced++;
        else break;
    }
    return produced;
}
