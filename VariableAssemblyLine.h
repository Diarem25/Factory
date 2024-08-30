#ifndef VARIABLEASSEMBLYLINE_H
#define VARIABLEASSEMBLYLINE_H

#include "VariableStorage.h"

class VariableAssemblyLine {
    int productType;
    int dailyProduction;
    VariableStorage& storage;

public:
    VariableAssemblyLine(VariableStorage& storage);
    void setProductType(int pType);
    int produce();
};

#endif
