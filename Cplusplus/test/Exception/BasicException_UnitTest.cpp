/* Header */
#include "Exception/BasicException.h"
#include "gtest/gtest.h"

// C++ standard libraries:
#include <exception>

// C standard libraries:
#include <string.h>

/* Type */

/* Test case */

TEST(RuntimeException, GetErrorMessage)
{
    /* Arrange */
    const char errorMsg[] = "Error event";
    Exception::RuntimeException sut(errorMsg);

    /* Act */
    const std::string result = sut.getMessage();

    /* Assert */
    EXPECT_EQ(strcmp(result.c_str(), errorMsg), 0);
}

TEST(RuntimeException, HandleException)
{
    /* Arrange */
    const char errorMsg[] = "Error event";
    Exception::RuntimeException sut(errorMsg);

    /* Act */
    try
    {
        throw Exception::RuntimeException(errorMsg);

        FAIL() << "Should throw exception";
    }
    catch (const Exception::RuntimeException& sut)
    {
        const std::string result = sut.getMessage();

        /* Assert */
        EXPECT_EQ(strcmp(result.c_str(), errorMsg), 0);
    }
    catch (const std::exception& error)
    {
        FAIL() << "Throw wrong exception";
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
