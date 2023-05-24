#pragma once
#include <iostream>
#include "MagicalContainer.h"

class SideCrossIterator
{
private:
public:
    SideCrossIterator(MagicalContainer container);
    int *begin();
    int *end();
};
