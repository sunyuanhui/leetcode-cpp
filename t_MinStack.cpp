#include "MinStack.h"
#include "gtest\gtest.h"

class TestFixtureMinStack : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(TestFixtureMinStack, TestCases) {
    MinStack min_stack;
    min_stack.push(2);
    min_stack.push(0);
    min_stack.push(3);
    min_stack.push(0);
    EXPECT_EQ(min_stack.getMin(), 0);
    min_stack.pop();
    EXPECT_EQ(min_stack.getMin(), 0);
    min_stack.pop();
    EXPECT_EQ(min_stack.getMin(), 0);
    min_stack.pop();
    EXPECT_EQ(min_stack.getMin(), 2);
}
