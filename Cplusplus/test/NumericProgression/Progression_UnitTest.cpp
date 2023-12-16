/* Header */
#include "NumericProgression/Progression.h"
#include "gtest/gtest.h"

/* Macro */

#define FIRST_VALUE (0)

/* Type */

typedef uint64_t dataType;

/* Prototype */

/* Variable */

/* Function */

TEST(Progression, printOne)
{
    /* Arrange */
    NumericProgression::Progression sut(FIRST_VALUE);

    /* Act */
    sut.printProgression(1);

    /* Assert */
}

TEST(Progression, printTwo)
{
    /* Arrange */
    NumericProgression::Progression sut(FIRST_VALUE);

    /* Act */
    sut.printProgression(2);

    /* Assert */
}

TEST(Progression, printOneHundred)
{
    /* Arrange */
    NumericProgression::Progression sut(FIRST_VALUE);

    /* Act */
    sut.printProgression(100);

    /* Assert */
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
