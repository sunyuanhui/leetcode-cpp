#include "TextFixture.h"
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        return 0;
    }
};

TEST_F(LeetCodeTestFixture, RomantoInteger) {
    Solution solution;
	int integer;
	integer = solution.romanToInt("I");
    EXPECT_EQ(integer, 1);
}
