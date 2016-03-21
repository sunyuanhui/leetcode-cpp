#include "TextFixture.h"

using namespace std;

class Solution {
public:
    int isPalindrome(int x) {
        return false;
    }
};

TEST_F(LeetCodeTestFixture, PalindromeNumber) {
    Solution solution;
	bool is_palindrome;
	is_palindrome = solution.isPalindrome(1234321);
    EXPECT_TRUE(is_palindrome);
}
