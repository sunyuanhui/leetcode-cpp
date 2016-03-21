#include "TextFixture.h"

using namespace std;

class Solution {
public:
    int isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int y = 0;
        int z = x;
        while (x != 0) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return y == z;
    }
};

TEST_F(LeetCodeTestFixture, PalindromeNumber) {
    Solution solution;
	bool is_palindrome;
	is_palindrome = solution.isPalindrome(1234321);
    EXPECT_TRUE(is_palindrome);

	is_palindrome = solution.isPalindrome(-2147447412);
    EXPECT_TRUE(!is_palindrome);
}
