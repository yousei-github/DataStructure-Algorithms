/* Header */
#include <stdlib.h>

#include "Array/BasicArray.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

typedef int instantiationType;

enum class Element : instantiationType
{
    One = 0,
    Two,
    Three,
    Max
};

struct EntryOrganization
{
    instantiationType element;
    uint32_t number;

    EntryOrganization& operator=(const EntryOrganization& v1)
    {
        if (this != &v1) // Avoid self-assignment
        {
            element = v1.element;
            number  = v1.number;
        }

        return *this; // Allow to chain together assignments
    }

} const entryTable[instantiationType(Element::Max)] = {
    {  instantiationType(Element::One), 68},
    {  instantiationType(Element::Two), 89},
    {instantiationType(Element::Three),  2}
};

/* Prototype */

/* Variable */

/* Function */

TEST(BasicArray, CopyByConstructor)

{
    /* Arrange */
    Array::BasicArray<instantiationType> arrayA(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        arrayA.add(entry);
    }

    /* Act */
    Array::BasicArray<instantiationType> sut(arrayA);

    /* Assert */
    EXPECT_EQ(sut.size(), arrayA.size());
    EXPECT_EQ(sut.occupancy(), arrayA.occupancy());
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i], arrayA[i]);
    }
}

TEST(BasicArray, CopyByOperator)
{
    /* Arrange */
    Array::BasicArray<instantiationType> arrayA(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        arrayA.add(entry);
    }

    Array::BasicArray<instantiationType> sut;

    /* Act */
    sut = arrayA;

    /* Assert */
    EXPECT_EQ(sut.size(), arrayA.size());
    EXPECT_EQ(sut.occupancy(), arrayA.occupancy());
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i], arrayA[i]);
    }
}

TEST(BasicArray, SecondCopy)
{
    /* Arrange */
    Array::BasicArray<instantiationType> arrayA(instantiationType(Element::Max)), arrayB;
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        arrayA.add(entry);
    }

    Array::BasicArray<instantiationType> sut;

    /* Act */
    sut = arrayB = arrayA;

    /* Assert */
    EXPECT_EQ(sut.size(), arrayA.size());
    EXPECT_EQ(sut.occupancy(), arrayA.occupancy());
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i], arrayA[i]);
    }
}

TEST(BasicArray, Empty)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(0);

    /* Act */
    bool isEmpty = sut.empty();

    /* Assert */
    EXPECT_TRUE(isEmpty) << "The array should be empty";
}

TEST(BasicArray, MaximumSize)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));

    /* Act */
    uint32_t size = sut.size();

    /* Assert */
    EXPECT_EQ(size, instantiationType(Element::Max)) << "The size of array should be " << instantiationType(Element::Max);
}

TEST(BasicArray, GetThirdElement)
{
    /* Arrange */;
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    struct EntryOrganization sortedEntryTable[instantiationType(Element::Max)];
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sortedEntryTable[i] = entryTable[i];
    }
    qsort(sortedEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); });

    /* Act */
    instantiationType thirdElement = sut[2].getElement();

    /* Assert */
    EXPECT_EQ(thirdElement, sortedEntryTable[2].element) << "The third element should be " << sortedEntryTable[2].element;
}

TEST(BasicArray, StoreHighestNumberInDescendingOrder)
{
    /* Arrange */;
    struct EntryOrganization sortedEntryTable[instantiationType(Element::Max)];
    for (size_t i = instantiationType(Element::One); i < instantiationType(Element::Max); i++)
    {
        sortedEntryTable[i] = entryTable[i];
    }
    qsort(sortedEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); });

    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));

    /* Act */
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    /* Assert */
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i].getElement(), sortedEntryTable[i].element) << "The " << i << "th element should be " << sortedEntryTable[i].element;
    }
}

TEST(BasicArray, RemoveAllElements)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    /* Act */
    sut.clear();

    /* Assert */
    EXPECT_EQ(sut.size(), 0) << "The size of array should be 0";
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
