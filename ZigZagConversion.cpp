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

        size_t len = s.length();
        for (size_t i = 0; i < len; ++i) {
            int row = calRow(numRows, i);
            int group = calGroup(numRows, i);
            cout << "row=" << row << " group " << group << endl;
        }

        string result;
        int column = calGroupCount(s, numRows);
        return result;
    }
    int calGroupCount(const string &s, int numRows) {
        size_t len = s.length();
        int group_num = top_and_bottom + (numRows - top_and_bottom) * 2;
        if (group_num > 0) {
            return len / group_num + (((len % group_num) != 0) ? 1 : 0);
        } else {
            return 0;
        }
    }
    int calGroup(int numRows, int index) {
        int group_num = top_and_bottom + (numRows - top_and_bottom) * 2;
        return index / group_num;
    }
    int calRow(int numRows, int index) {
        int group_num = top_and_bottom + (numRows - top_and_bottom) * 2;
        int index_in_group = index % group_num;
        return index_in_group < numRows ? index_in_group : group_num - index_in_group;
    }

    const int top_and_bottom = 2;
};

TEST_F(LeetCodeTestFixture, ZigZagConversion) {
    Solution solution;
    string origin = "PAYPALISHIRING";
	string result;
    int column;
    int long_column;
    int group_num;

	result = solution.convert(origin, 1);
    EXPECT_EQ(result, "PAYPALISHIRING");

    //P Y A I H R N
    //A P L S I I G
    group_num = solution.calGroupCount(origin, 2);
    EXPECT_EQ(group_num, 7);
    result = solution.convert(origin, 2);
    EXPECT_EQ(result, "PYAIHRNAPLSIIG");

    //P   A   H   N
    //A P L S I I G
    //Y   I   R
    group_num = solution.calGroupCount(origin, 3);
    EXPECT_EQ(group_num, 4);
    result = solution.convert(origin, 3);
    EXPECT_EQ(result, "PAHNAPLSIIGYIR");

    //P   I   N
    //A L S I G
    //Y A H R 
    //P   I 
    group_num = solution.calGroupCount(origin, 4);
    EXPECT_EQ(group_num, 3);
   result = solution.convert(origin, 4);
   EXPECT_EQ(result, "PINALSIGYAHRPI");
}
