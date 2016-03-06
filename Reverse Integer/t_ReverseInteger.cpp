#include "ReverseInteger.h"
#include "gtest\gtest.h"

class TestFixtureReverseInteger : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(TestFixtureReverseInteger, TestCases) {
    Solution solution;
	int reverse;
	reverse = solution.reverse(1234);
    EXPECT_EQ(reverse, 4321);
	reverse = solution.reverse(-1234);
    EXPECT_EQ(reverse, -4321);
	reverse = solution.reverse(0x80000000);
    EXPECT_EQ(reverse, 0);
	reverse = solution.reverse(10);
    EXPECT_EQ(reverse, 1);
	reverse = solution.reverse(1534236469);
    EXPECT_EQ(reverse, 0);
}
