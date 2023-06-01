#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Check the class MagicalContainer")
{
    SUBCASE("Default constructor")
    {
        CHECK_NOTHROW(MagicalContainer());
        MagicalContainer container;
        CHECK_EQ(container.size(), 0);
    }

    SUBCASE("addElement() and removeElement()")
    {
        MagicalContainer container;

        CHECK_NOTHROW(container.addElement(1));
        CHECK_EQ(container.size(), 1);

        CHECK_NOTHROW(container.addElement(2));
        CHECK_EQ(container.size(), 2);

        CHECK_NOTHROW(container.addElement(3));
        CHECK_EQ(container.size(), 3);

        CHECK_NOTHROW(container.removeElement(2));
        CHECK_EQ(container.size(), 2);

        CHECK_THROWS(container.removeElement(4));
        CHECK_EQ(container.size(), 2);

        CHECK_NOTHROW(container.removeElement(1));
        CHECK_EQ(container.size(), 1);

        CHECK_NOTHROW(container.removeElement(3));
        CHECK_EQ(container.size(), 0);
    }

    SUBCASE("AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        CHECK_NOTHROW(MagicalContainer::AscendingIterator iter(container));
        MagicalContainer::AscendingIterator iter(container);

        CHECK_EQ(*iter, 2);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 3);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 9);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 17);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 25);
        CHECK_NOTHROW(++iter);
        CHECK(iter == iter.end());
        CHECK_NOTHROW(++iter);
        CHECK(iter == iter.end());

        // Additional checks to test AscendingIterator's copy constructor and assignment operators

        MagicalContainer::AscendingIterator iterCopy(iter);
        CHECK_EQ(*iterCopy, 25);
        CHECK_NOTHROW(++iterCopy);
        CHECK(iterCopy == iterCopy.end());

        MagicalContainer::AscendingIterator iterCopy2 = iter;
        CHECK_EQ(*iterCopy2, 25);
        CHECK_NOTHROW(++iterCopy2);
        CHECK(iterCopy2 == iterCopy2.end());

        CHECK(iter != iter.end()); // Check operator!= for inequality
        CHECK(iter.end() != iter); // Check operator!= for inequality (reversed)

        // Check operator>
        CHECK(iter > iterCopy);
        CHECK(!(iterCopy > iter));

        // Check operator<
        CHECK(iterCopy < iter);
        CHECK(!(iter < iterCopy));
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        CHECK_NOTHROW(MagicalContainer::SideCrossIterator iter(container));
        MagicalContainer::SideCrossIterator iter(container);

        CHECK_EQ(*iter, 2);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 25);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 3);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 17);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 9);
        CHECK_NOTHROW(++iter);
        CHECK(iter == iter.end());
        CHECK_NOTHROW(++iter);
        CHECK(iter == iter.end());

        // Additional checks to test SideCrossIterator's copy constructor and assignment operators

        MagicalContainer::SideCrossIterator iterCopy(iter);
        CHECK_EQ(*iterCopy, 9);
        CHECK_NOTHROW(++iterCopy);
        CHECK(iterCopy == iterCopy.end());

        MagicalContainer::SideCrossIterator iterCopy2 = iter;
        CHECK_EQ(*iterCopy2, 9);
        CHECK_NOTHROW(++iterCopy2);
        CHECK(iterCopy2 == iterCopy2.end());

        CHECK(iter != iter.end()); // Check operator!= for inequality
        CHECK(iter.end() != iter); // Check operator!= for inequality (reversed)

        // Check operator>
        CHECK(iter > iterCopy);
        CHECK(!(iterCopy > iter));

        // Check operator<
        CHECK(iterCopy < iter);
        CHECK(!(iter < iterCopy));
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);

        CHECK_NOTHROW(MagicalContainer::PrimeIterator iter(container));
        MagicalContainer::PrimeIterator iter(container);

        CHECK_EQ(*iter, 2);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 3);
        CHECK_NOTHROW(++iter);
        CHECK_EQ(*iter, 17);
        CHECK_NOTHROW(++iter);
        CHECK(iter == iter.end());
        CHECK_NOTHROW(++iter);
        CHECK(iter == iter.end());

        // Additional checks to test PrimeIterator's copy constructor and assignment operators

        MagicalContainer::PrimeIterator iterCopy(iter);
        CHECK(iterCopy == iterCopy.end());

        MagicalContainer::PrimeIterator iterCopy2 = iter;
        CHECK(iterCopy2 == iterCopy2.end());

        CHECK(iter != iter.end()); // Check operator!= for inequality
        CHECK(iter.end() != iter); // Check operator!= for inequality (reversed)

        // Check operator>
        CHECK(iter > iterCopy);
        CHECK(!(iterCopy > iter));

        // Check operator<
        CHECK(iterCopy < iter);
        CHECK(!(iter < iterCopy));
    }
}
