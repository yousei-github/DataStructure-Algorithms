
/* Header */
#include <HippoMocks/hippomocks.h>
#include <time.h>

#include <iostream>
#include <string>

#include "ProjectConfiguration.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

/* Macro */

/* Type */

class Environment : public testing::Environment
{
public:
    Environment() = default;

    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override { g_environment_set_up_count++; }

    // Override this to define how to tear down the environment.
    void TearDown() override { g_environment_tear_down_count++; }

    // Global environment variables
    static int g_environment_set_up_count;
    static int g_environment_tear_down_count;
};

class FixtureClass : public testing::Test
{
public:
    /**
     * Per-test-suite set-up.
     * Called before the first test in this test suite.
     * Can be omitted if not needed.
     */
    static void SetUpTestSuite()
    {
        shared_resource = new double;
    }

    /**
     * Per-test-suite tear-down.
     * Called after the last test in this test suite.
     * Can be omitted if not needed.
     */
    static void TearDownTestSuite()
    {
        delete shared_resource;
        shared_resource = {};
    }

protected:
    // You can remove any or all of the following functions if their bodies would be empty.

    FixtureClass()
    {
        // You can do set-up work for each test here.
    }

    ~FixtureClass()
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up and cleaning up each test, you can define the following methods:
    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right before each test, which means the per-test set-up).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right before the destructor, which means the per-test tear-down).
    }

    // Set up the mock
    void MockSetUp(MockRepository& mocks)
    {
        // You can do mock set-up work for each test here.

        mocks.OnCallFunc(clock).Return(CURRENT_CLOCK);
    }

    // Class members declared here can be used by all tests in the test suite for FixtureClass.
    const char name[12]            = "Hello World";
    const uint32_t name_length     = sizeof(name);
    const clock_t CURRENT_CLOCK    = 10000;
    const uint32_t TIMER_FREQUENCY = 50;
    const clock_t CURRENT_TIME     = CURRENT_CLOCK / TIMER_FREQUENCY;

    // Declare some expensive resource shared by all tests.
    static double* shared_resource;
};

/** 
 * Two ways to define a fixture class for value-parameterized tests:
 * (1) Implement all the usual fixture class members;
 * (2) Add parameters to a pre-existing fixture class.
 */

// class ValueParameterizedClass : public testing ::TestWithParam<int>
// {
//     // You can implement all the usual fixture class members here.
//     // To access the test parameter, call GetParam() from class TestWithParam<T>.
// };

class ValueParameterizedClass : public FixtureClass, public testing::WithParamInterface<int>
{
    // The usual test fixture members go here too.
protected:
    ValueParameterizedClass(): count(0) {}

    int count;
    static int global_count;
};

/* Prototype */
INSTANTIATE_TEST_SUITE_P(InstantiationOne, ValueParameterizedClass, testing::Range(0, 5));

/* Variable */
// Global environment variables
int Environment::g_environment_set_up_count    = {};
int Environment::g_environment_tear_down_count = {};

// Define the shared resource of member variables
double* FixtureClass::shared_resource          = {};

int ValueParameterizedClass::global_count      = {};

/* Function */

// Simple Tests
TEST(TestSuiteName, TestName)
{
    // ASSERT_* versions generate fatal failures when they fail, and abort the current function.
    ASSERT_EQ(1 + 1, 2) << "1 + 1 should equal to 2.";

    // EXPECT_* versions generate nonfatal failures, which don’t abort the current function.
    EXPECT_EQ(1 + 1, 2) << "1 + 1 should equal to 2.";

    // Explicit Success and Failure
    switch (1 + 1)
    {
    case 2:
    {
        // Generates a success.
        SUCCEED();
    }
    break;
    case 3:
    {
        // Generates a nonfatal failure, which allows the current function to continue running.
        ADD_FAILURE();
    }
    break;
    case 4:
    {
        // Generates a nonfatal failure, which allows the current function to continue running.
        ADD_FAILURE_AT(__func__, __LINE__);
    }
    break;
    default:
    {
        // Generates a fatal failure, which returns from the current function.
        FAIL() << "We shouldn't get here.";
    }
    break;
    }

    /* Exception Assertions */
    // Verifies that statement does not throw any exception: EXPECT_NO_THROW(statement)
    EXPECT_NO_THROW(
        {
            int count = 5;
            while (count)
            {
                count--;
                SUCCEED();
            }
        });

    // Verifies that statement throws an exception of any type: EXPECT_ANY_THROW(statement)

    class CommonException
    {
    public:
        CommonException(const std::string& error)
        : errorMessage(error) {}

        std::string getError()
        {
            return errorMessage;
        }

    private:
        std::string errorMessage;
    };

    EXPECT_ANY_THROW(
        {
            int dividend = 5;
            int divisor  = 0;

            if (divisor == 0) // Attempt to divide by 0?
            {
                throw CommonException("Divide by zero");
            }

            int quotient = dividend / divisor;
            SUCCEED() << "The quotient is " << quotient;
        });
}

TEST(TestSuiteName, SkippedTest)
{
    GTEST_SKIP() << "Skipping single test";
    FAIL() << "We shouldn't get here.";
}

TEST(TestSuiteName, GlobalEnvironment)
{
    EXPECT_NE(Environment::g_environment_set_up_count, 0);
    EXPECT_EQ(Environment::g_environment_tear_down_count, 0);
}

// Test Fixtures
TEST_F(FixtureClass, Factorial)
{
    // Access class members
    EXPECT_EQ(sizeof(name), name_length);

    // Verifies that value matches the matcher: EXPECT_THAT(value, matcher)
    EXPECT_THAT(name, testing::StartsWith("Hello"));
    ASSERT_THAT(1 + 1, testing::AllOf(testing::Gt(1), testing::Lt(3)));

    // Verifies that condition is true: EXPECT_TRUE(condition)
    EXPECT_TRUE(true);

    // Verifies that condition is false: EXPECT_FALSE(condition)
    EXPECT_FALSE(false);

    // Verifies that val1 == val2: EXPECT_EQ(val1, val2)
    EXPECT_EQ(false, 0);

    // Verifies that val1 != val2: EXPECT_NE(val1, val2)
    EXPECT_NE(true, false);

    // Verifies that val1 < val2: EXPECT_LT(val1, val2)
    EXPECT_LT(0, 1);

    // Verifies that val1 <= val2: EXPECT_LE(val1, val2)
    EXPECT_LE(0, 1);

    // Verifies that val1 > val2: EXPECT_GT(val1, val2)
    EXPECT_GT(1, 0);

    // Verifies that val1 >= val2: EXPECT_GE(val1, val2)
    EXPECT_GE(1, 0);
}

// Value-Parameterized Tests
TEST_P(ValueParameterizedClass, Counting)
{
    count++;
    global_count++;

    EXPECT_EQ(count, 1);
    EXPECT_GE(global_count, count);

    // Inside a test, access the test parameter with the GetParam() method of the TestWithParam<T> class:
    std::cout << "The global_count is " << global_count << " at the " << GetParam() + 1 << "th test." << std::endl;
}

// Mock Tests
TEST_F(FixtureClass, MockTimer)
{
    MockRepository mocks;
    MockSetUp(mocks);

    clock_t currentClock = clock();
    EXPECT_EQ(currentClock, CURRENT_CLOCK) << "The current clock should be " << CURRENT_CLOCK << ".";
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    testing::AddGlobalTestEnvironment(new Environment); // You should call AddGlobalTestEnvironment() before RUN_ALL_TESTS() is called.
    return RUN_ALL_TESTS();
}