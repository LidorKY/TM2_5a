#pragma once
#include <iostream>
#include <list>

using namespace std;

class MagicalContainer
{
private:
    list<int> container;

public:
    /* Constructor */
    MagicalContainer();

    /* Functions */
    void addElement(int num);
    void removeElement(int num);
    int size();
};