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
        int column = calColumn(s, numRows);
        return result;
    }
    int calColumn(const string &s, int numRows) {
        size_t len = s.length();
        int column = 0;
        const int tb = 2; // top & bottom
        const int column_num = numRows + (numRows - tb);
        while (len != 0) {
            column++;
            if (len < column_num) {
                break;
            }
            len = len - column_num;
        }
        return column;
    }
};

TEST_F(LeetCodeTestFixture, ZigZagConversion) {
    Solution solution;
    string origin = "PAYPALISHIRING";
	string result;
    int column;

	result = solution.convert(origin, 1);
    EXPECT_EQ(result, "PAYPALISHIRING");

    //P Y A I H R N
    //A P L S I I G
    column = solution.calColumn(origin, 2);
    EXPECT_EQ(column, 7);
	result = solution.convert(origin, 2);
    EXPECT_EQ(result, "PYAIHRNAPLSIIG");

    //P   A   H   N
    //A P L S I I G
    //Y   I   R
    column = solution.calColumn(origin, 3);
    EXPECT_EQ(column, 4);
	result = solution.convert(origin, 3);
    EXPECT_EQ(result, "PAHNAPLSIIGYIR");

    //P     I     N
    //A   L S   I G
    //Y A   H R 
    //P     I 
    column = solution.calColumn(origin, 4);
    EXPECT_EQ(column, 3);
	result = solution.convert(origin, 4);
    EXPECT_EQ(result, "PINALSIGYAHRPI");
}
