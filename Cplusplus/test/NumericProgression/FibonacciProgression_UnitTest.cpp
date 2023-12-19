/* Header */
#include "NumericProgression/FibonacciProgression.h"
#include "gtest/gtest.h"

/* Macro */

#define FIRST_VALUE  (0)
#define SECOND_VALUE (1)

/* Type */

typedef uint64_t dataType;

/* Prototype */

/* Variable */

/* Function */

TEST(FibonacciProgression, printOne)
{
    /* Arrange */
    NumericProgression::FibonacciProgression sut(FIRST_VALUE, SECOND_VALUE);

    /* Act */
    sut.printProgression(1);

    /* Assert */
}

TEST(FibonacciProgression, printTwo)
{
    /* Arrange */
    NumericProgression::FibonacciProgression sut(FIRST_VALUE, SECOND_VALUE);

    /* Act */
    sut.printProgression(2);

    /* Assert */
}

TEST(FibonacciProgression, printOneHundred)
{
    /* Arrange */
    NumericProgression::FibonacciProgression sut(FIRST_VALUE, SECOND_VALUE);

    /* Act */
    sut.printProgression(100);

    /* Assert */
}

TEST(FibonacciProgression, Polymorphism)
{
    /* Arrange */
    NumericProgression::Progression* sut = new NumericProgression::FibonacciProgression(FIRST_VALUE, SECOND_VALUE);

    /* Act */
    sut->printProgression(100);

    /* Assert */
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
