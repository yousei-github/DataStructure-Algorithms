/* Header */
#include <stdlib.h>
#include <string.h>

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

TEST(BasicArray, Occupancy)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    sut.remove(0);

    /* Act */
    uint32_t occupancy = sut.occupancy();

    /* Assert */
    EXPECT_EQ(occupancy, instantiationType(Element::Max) - 1) << "The occupancy of array should be " << instantiationType(Element::Max) - 1;
    EXPECT_EQ(sut.size(), instantiationType(Element::Max)) << "The size of array should be " << instantiationType(Element::Max);
}

TEST(BasicArray, StoreHighestNumberInDescendingOrder)
{
    /* Arrange */
    struct EntryOrganization ascendingOrderEntryTable[instantiationType(Element::Max)] = {};
    memcpy(ascendingOrderEntryTable, entryTable, sizeof(entryTable));
    qsort(ascendingOrderEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v1)->number - ((EntryOrganization*) v2)->number); }); // Sort in the ascending order

    struct EntryOrganization descendingOrderEntryTable[instantiationType(Element::Max)] = {};
    memcpy(descendingOrderEntryTable, entryTable, sizeof(entryTable));
    qsort(descendingOrderEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); }); // Sort in the descending order

    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));

    /* Act */
    for (auto parameter : ascendingOrderEntryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    /* Assert */
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i].getElement(), descendingOrderEntryTable[i].element) << "The " << i << "th element should be " << descendingOrderEntryTable[i].element;
    }
}

TEST(BasicArray, RemoveFirstElement)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    struct EntryOrganization descendingOrderEntryTable[instantiationType(Element::Max)] = {};
    memcpy(descendingOrderEntryTable, entryTable, sizeof(entryTable));
    qsort(descendingOrderEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); }); // Sort in the descending order

    /* Act */
    instantiationType firstElement = sut.remove(0).getElement();

    /* Assert */
    EXPECT_EQ(sut.size(), instantiationType(Element::Max));
    EXPECT_EQ(sut.occupancy(), instantiationType(Element::Max) - 1);
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i].getElement(), descendingOrderEntryTable[i + 1].element);
    }
    EXPECT_EQ(firstElement, descendingOrderEntryTable[0].element) << "The first element should be " << descendingOrderEntryTable[0].element;
}

TEST(BasicArray, RemoveLastElement)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    struct EntryOrganization descendingOrderEntryTable[instantiationType(Element::Max)] = {};
    memcpy(descendingOrderEntryTable, entryTable, sizeof(entryTable));
    qsort(descendingOrderEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); }); // Sort in the descending order

    /* Act */
    instantiationType lastElement = sut.remove(instantiationType(Element::Max) - 1).getElement();

    /* Assert */
    EXPECT_EQ(sut.size(), instantiationType(Element::Max));
    EXPECT_EQ(sut.occupancy(), instantiationType(Element::Max) - 1);
    for (size_t i = 0; i < sut.occupancy(); i++)
    {
        EXPECT_EQ(sut[i].getElement(), descendingOrderEntryTable[i].element);
    }
    EXPECT_EQ(lastElement, descendingOrderEntryTable[instantiationType(Element::Max) - 1].element) << "The last element should be " << descendingOrderEntryTable[instantiationType(Element::Max) - 1].element;
}

TEST(BasicArray, GetFirstElement)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    struct EntryOrganization descendingOrderEntryTable[instantiationType(Element::Max)] = {};
    memcpy(descendingOrderEntryTable, entryTable, sizeof(entryTable));
    qsort(descendingOrderEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); }); // Sort in the descending order

    /* Act */
    instantiationType firstElement = sut[0].getElement();

    /* Assert */
    EXPECT_EQ(firstElement, descendingOrderEntryTable[0].element) << "The first element should be " << descendingOrderEntryTable[0].element;
}

TEST(BasicArray, GetLastElement)
{
    /* Arrange */
    Array::BasicArray<instantiationType> sut(instantiationType(Element::Max));
    for (auto parameter : entryTable)
    {
        Array::ArrayEntry<instantiationType> entry(parameter.element, parameter.number);
        sut.add(entry);
    }

    struct EntryOrganization descendingOrderEntryTable[instantiationType(Element::Max)] = {};
    memcpy(descendingOrderEntryTable, entryTable, sizeof(entryTable));
    qsort(descendingOrderEntryTable, instantiationType(Element::Max), sizeof(EntryOrganization), [](const void* v1, const void* v2) -> int
        { return (((EntryOrganization*) v2)->number - ((EntryOrganization*) v1)->number); }); // Sort in the descending order

    /* Act */
    instantiationType lastElement = sut[instantiationType(Element::Max) - 1].getElement();

    /* Assert */
    EXPECT_EQ(lastElement, descendingOrderEntryTable[instantiationType(Element::Max) - 1].element) << "The last element should be " << descendingOrderEntryTable[instantiationType(Element::Max) - 1].element;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
