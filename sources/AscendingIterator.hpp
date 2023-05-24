#pragma once
#include <iostream>
#include "MagicalContainer.h"

class AscendingIterator
{
private:
public:
    AscendingIterator(MagicalContainer container);
    int *begin();
    int *end();
};