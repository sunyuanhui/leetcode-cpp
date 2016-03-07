#include "TextFixture.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
		int y = 0;
		while (x != 0) {
            int remainder = x % 10;
			int next = y * 10 + remainder;
            if ((next - remainder) / 10 != y) {
                return 0;
            }
            y = next;
			x = x / 10;
		}
        return y;
    }
};

TEST_F(LeetCodeTestFixture, ReverseInteger) {
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
