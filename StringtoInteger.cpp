#include "TextFixture.h"
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const int error = 0;
        if (str.size() == 0) {
            return error;
        }

        size_t start = str.find_first_not_of(' ');
        if (start == string::npos) {
            return error;
        }

        int integer = 0;
        for (size_t i = start; i < str.size(); i++) {
            char num_char = str.at(i);
            if ('0' <= num_char && num_char <= '9') {
                int number = num_char - '0';
                int next = integer * 10 + number;
                if (next - integer * 10 == number) {
                    integer = next;
                } else {
                    return error;
                }
            } else if (num_char == ' ') {
                continue;
            } else {
                return error;
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

	integer = solution.myAtoi("  4321 1 ");
    EXPECT_EQ(integer, 43211);

	integer = solution.myAtoi("  +1 ");
    EXPECT_EQ(integer, 1);
}
