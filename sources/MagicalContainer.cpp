#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
using namespace std;

using namespace std;

/* MagicalContainer */

MagicalContainer::MagicalContainer()
{
    this->container = vector<int>();
}

void MagicalContainer::addElement(int num)
{
    for (unsigned long i = 0; i < this->container.size(); i++)
    {
        if (this->container[i] > num)
        {
            this->container.insert(this->container.begin() + (long)i, num);
            return;
        }
    }
    this->container.emplace_back(num);
}

void MagicalContainer::removeElement(int num)
{
    for (size_t i = 0; i < this->container.size(); i++)
    {
        if (this->container[i] == num)
        {
            this->container.erase(this->container.begin() + (long)i);
            return;
        }
    }
    throw "Element not found";
}

int MagicalContainer::size()
{
    // Return size of container
    return this->container.size();
}

/* AscendingIterator */

MagicalContainer::AscendingIterator::AscendingIterator()
{
    this->index = 0;
    this->pointer_container = nullptr;
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container)
{
    this->index = 0;
    this->pointer_container = &container;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
{
    // Copy constructor
    this->index = other.index;
    this->pointer_container = other.pointer_container;
}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept
{
    // Move constructor
    this->index = other.index;
    this->pointer_container = other.pointer_container;
}

MagicalContainer::AscendingIterator::~AscendingIterator()
{
    // Destructor
    this->index = 0;
    this->pointer_container = nullptr;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    // Assignment operator
    if (this == &other)
    {
        return *this;
    }
    else
    {
        this->index = other.index;
        this->pointer_container = other.pointer_container;
    }
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
{
    // Move assignment operator
    if (this == &other)
    {
        return *this;
    }
    else
    {
        this->index = other.index;
        this->pointer_container = other.pointer_container;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    // Equality operator
    if (this->index == other.index && this->pointer_container == other.pointer_container)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    // Inequality operator
    if (this->index != other.index || this->pointer_container != other.pointer_container)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const
{
    // Greater than operator
    if (this->index > other.index)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const
{
    // Less than operator
    if (this->index < other.index)
    {
        return true;
    }
    return false;
}

int &MagicalContainer::AscendingIterator::operator*()
{
    // Dereference operator
    return this->pointer_container->container[this->index];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    // Pre-increment operator
    this->index++;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    // Begin iterator
    this->index = 0;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    // End iterator
    this->index = this->pointer_container->container.size();
    return *this;
}

/* SideCrossIterator */

MagicalContainer::SideCrossIterator::SideCrossIterator()
{
    // Default constructor
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer container)
{
    // Constructor with container argument
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
{
    // Copy constructor
}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept
{
    // Move constructor
}

MagicalContainer::SideCrossIterator::~SideCrossIterator()
{
    // Destructor
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    // Assignment operator
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
{
    // Move assignment operator
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    // Equality operator
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    // Inequality operator
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const
{
    // Greater than operator
    if (this->index > other.index)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const
{
    // Less than operator
    if (this->index < other.index)
    {
        return true;
    }
    return false;
}

int &MagicalContainer::SideCrossIterator::operator*()
{
    // Dereference operator
    static int dummyValue = 0;
    return dummyValue;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    // Pre-increment operator
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    // Begin iterator
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    // End iterator
    return *this;
}

/* PrimeIterator */

MagicalContainer::PrimeIterator::PrimeIterator()
{
    // Default constructor
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer container)
{
    // Constructor with container argument
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
{
    // Copy constructor
}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept
{
    // Move constructor
}

MagicalContainer::PrimeIterator::~PrimeIterator()
{
    // Destructor
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    // Assignment operator
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept
{
    // Move assignment operator
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    // Equality operator
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    // Inequality operator
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const
{
    // Greater than operator
    if (this->index > other.index)
    {
        return true;
    }
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const
{
    // Less than operator
    if (this->index < other.index)
    {
        return true;
    }
    return false;
}

int &MagicalContainer::PrimeIterator::operator*()
{
    // Dereference operator
    static int dummyValue = 0;
    return dummyValue;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    // Pre-increment operator
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    // Begin iterator
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    // End iterator
    return *this;
}
