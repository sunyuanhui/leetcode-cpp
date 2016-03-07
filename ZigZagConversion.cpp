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

        int tb = 2; // top & bottom
        size_t s_len = s.length();
        string result;

        for (int i = 0; i < numRows; ++i) {
            if (i == numRows - 1) {
                tb = 1;
            }

            int col = 0;
            do 
            {
                int index = (tb + (numRows - tb) * 2) * col;
                if (index < s_len) {
                    result.push_back(s.at(index));
                } else {
                    break;
                }
                col++;
            } while (1);
        }
        return result;
    }
};

TEST_F(LeetCodeTestFixture, ZigZagConversion) {
    Solution solution;
	string result;

	result = solution.convert("PAYPALISHIRING", 1);
    EXPECT_EQ(result, "PAYPALISHIRING");

    //P Y A I H R N
    //A P L S I I G
	result = solution.convert("PAYPALISHIRING", 2);
    EXPECT_EQ(result, "PYAIHRNAPLSIIG");

    //P   A   H   N
    //A P L S I I G
    //Y   I   R
	result = solution.convert("PAYPALISHIRING", 3);
    EXPECT_EQ(result, "PAHNAPLSIIGYIR");

    //P     I     N
    //A   L S   I G
    //Y A   H R 
    //P     I 
	result = solution.convert("PAYPALISHIRING", 4);
    EXPECT_EQ(result, "PINALSIGYAHRPI");
}
