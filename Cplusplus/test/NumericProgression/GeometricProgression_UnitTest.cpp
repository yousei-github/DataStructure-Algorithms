/* Header */
#include "NumericProgression/GeometricProgression.h"
#include "gtest/gtest.h"

/* Macro */

#define FIRST_VALUE (1)
#define BASE_VALUE  (2)

/* Type */

typedef uint64_t dataType;

/* Prototype */

/* Variable */

/* Function */

TEST(GeometricProgression, printOne)
{
    /* Arrange */
    NumericProgression::GeometricProgression sut(FIRST_VALUE, BASE_VALUE);

    /* Act */
    sut.printProgression(1);

    /* Assert */
}

TEST(GeometricProgression, printTwo)
{
    /* Arrange */
    NumericProgression::GeometricProgression sut(FIRST_VALUE, BASE_VALUE);

    /* Act */
    sut.printProgression(2);

    /* Assert */
}

TEST(GeometricProgression, printOneHundred)
{
    /* Arrange */
    NumericProgression::GeometricProgression sut(FIRST_VALUE, BASE_VALUE);

    /* Act */
    sut.printProgression(100);

    /* Assert */
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
