#include "../code/utilities.h" // Include the header file of the code to be tested.
#include "gtest/gtest.h" // Google Test Framework, must be included in the test file.

// ------------------------------------ SAMPLE UNIT TEST ------------------------------------
// Test case for the add function
// TEST (TestSuiteName, TestName)
TEST(AddFunctionTest, PositiveNumbers) {
    // Test input
    int a = 3;
    int b = 4;

    // Expected result
    int expected_sum = 7;

    // Call the add function
    int actual_sum = add(a, b);

    // EXPECT_EQ is a macro that compares the actual result with the expected result
    // the test will pass if the actual result is equal to the expected result
    // If the test fails, the message will be printed.
    // Check if the actual result matches the expected result
    EXPECT_EQ(actual_sum, expected_sum) << "The actual sum is not equal to the expected sum, Expected vs. Actual:"
                    << expected_sum << " vs. " << actual_sum;
}

// ---------------------------------------------------------------------------------------
