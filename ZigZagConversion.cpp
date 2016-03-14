#include "TextFixture.h"
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 0) {
            return string();
        } else if (numRows == 1) {
            return s;
        }

        string result;
        size_t len = s.length();

        const int top_and_bottom = 2;
        const int group_num = top_and_bottom + (numRows - top_and_bottom) * 2;

        for (size_t i = 0; i < len; i += group_num) {
            result.push_back(s.at(i));
        }

        for (int i = 1; i < numRows - 1; i++) {
            for (size_t j = i; j < len; j += group_num) {
                result.push_back(s.at(j));

                int group = j / group_num;
                int next = (group_num - i) + group * group_num;
                if (next < len) {
                    result.push_back(s.at(next));
                }
            }
        }

        for (size_t i = numRows - 1; i < len; i += group_num) {
            result.push_back(s.at(i));
        }
        return result;
    }
};

TEST_F(LeetCodeTestFixture, ZigZagConversion) {
    Solution solution;
	string result;
    string origin = "PAYPALISHIRING";

	result = solution.convert(origin, 1);
    EXPECT_EQ(result, "PAYPALISHIRING");

    //P Y A I H R N
    //A P L S I I G
    result = solution.convert(origin, 2);
    EXPECT_EQ(result, "PYAIHRNAPLSIIG");

    //P   A   H   N
    //A P L S I I G
    //Y   I   R
    result = solution.convert(origin, 3);
    EXPECT_EQ(result, "PAHNAPLSIIGYIR");

    //P   I   N
    //A L S I G
    //Y A H R 
    //P   I 
   result = solution.convert(origin, 4);
   EXPECT_EQ(result, "PINALSIGYAHRPI");
}
