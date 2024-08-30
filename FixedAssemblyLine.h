#ifndef FIXEDASSEMBLYLINE_H
#define FIXEDASSEMBLYLINE_H

#include "BaseStorage.h"

class FixedAssemblyLine {
    int dailyProduction;
    BaseStorage& storage;

public:
    FixedAssemblyLine(BaseStorage& storage);
    int produce();
};

#endif
