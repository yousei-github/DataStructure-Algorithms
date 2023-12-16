/* Header */
#include "NumericProgression/ArithmeticProgression.h"
#include "gtest/gtest.h"

/* Macro */

#define FIRST_VALUE     (1)
#define INCREMENT_VALUE (2)

/* Type */

typedef uint64_t dataType;

/* Prototype */

/* Variable */

/* Function */

TEST(ArithmeticProgression, printOne)
{
    /* Arrange */
    NumericProgression::ArithmeticProgression sut(FIRST_VALUE, INCREMENT_VALUE);

    /* Act */
    sut.printProgression(1);

    /* Assert */
}

TEST(ArithmeticProgression, printTwo)
{
    /* Arrange */
    NumericProgression::ArithmeticProgression sut(FIRST_VALUE, INCREMENT_VALUE);

    /* Act */
    sut.printProgression(2);

    /* Assert */
}

TEST(ArithmeticProgression, printOneHundred)
{
    /* Arrange */
    NumericProgression::ArithmeticProgression sut(FIRST_VALUE, INCREMENT_VALUE);

    /* Act */
    sut.printProgression(100);

    /* Assert */
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
