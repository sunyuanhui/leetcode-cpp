#include "TextFixture.h"
#include <limits.h>
#include <deque>

using namespace std;

class MinStack {
public:
    void push(int x) {
        m_stack.push_back(x);

        if (x < m_min_value)
            m_min_value = x;
    }

    void pop() {
        if (m_stack.empty()) {
            return;
        }

        int top_value = m_stack.back();
        m_stack.pop_back();

        if (top_value == m_min_value) {
            m_min_value = INT_MAX;

            for (auto iter : m_stack) {
                if (iter < m_min_value) {
                    m_min_value = iter;
                }
            }
        }
    }

    int top() {
        return !m_stack.empty() ? m_stack.back() : INT_MAX;
    }

    int getMin() {
        return m_min_value;
    }
    
private:
    deque<int> m_stack;
    int m_min_value = INT_MAX;
};

TEST_F(LeetCodeTestFixture, MinStack) {
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
