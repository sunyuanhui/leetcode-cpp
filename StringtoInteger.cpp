#include "TextFixture.h"
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        size_t start = str.find_first_not_of(' ');
        if (start == string::npos || str.size() == 0) {
            return 0;
        }

        int sign = 1;
        if (str.at(start) == '+') {
            start++;
        } else if (str.at(start) == '-') {
            start++;
            sign = -1;
        }

        long long integer = 0;
        for (size_t i = start; i < str.size(); i++) {
            char num_char = str.at(i);
            if ('0' <= num_char && num_char <= '9') {
                integer = integer * 10 + (num_char - '0') * sign;
                if (integer <= INT_MIN) {
                    return INT_MIN;
                } else if (integer >= INT_MAX) {
                    return INT_MAX;
                }
            } else {
                break;
            }
        }

        return integer;
    }
};

TEST_F(LeetCodeTestFixture, StringToInteger) {
    Solution solution;
	int integer;
	integer = solution.myAtoi("4321");
    EXPECT_EQ(integer, 4321);

	integer = solution.myAtoi("  4321  ");
    EXPECT_EQ(integer, 4321);
    
	integer = solution.myAtoi("  43a21  ");
    EXPECT_EQ(integer, 43);

	integer = solution.myAtoi("  4321 1 ");
    EXPECT_EQ(integer, 4321);

	integer = solution.myAtoi("  +1 ");
    EXPECT_EQ(integer, 1);

	integer = solution.myAtoi("  -1 ");
    EXPECT_EQ(integer, -1);

	integer = solution.myAtoi("2147483648");
    EXPECT_EQ(integer, 2147483647);

	integer = solution.myAtoi("9223372036854775809");
    EXPECT_EQ(integer, 2147483647);
}
