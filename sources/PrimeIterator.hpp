#pragma once
#include <iostream>
#include "MagicalContainer.h"

class PrimeIterator
{
private:
public:
    PrimeIterator(MagicalContainer container);
        int *begin();
    int *end();
};