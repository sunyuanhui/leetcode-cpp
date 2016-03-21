#include "TextFixture.h"
#include <string>

using namespace std;

class Solution {
public:
    //罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。
    //按照下述的规则可以表示任意正整数。需要注意的是罗马数字中没有“0”，与进位制无关。
    //重复数次：一个罗马数字重复几次，就表示这个数的几倍。
    //右加左减：
    //    在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
    //    在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
    //    左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
    //    但是，左减时不可跨越一个位值。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。
    //    左减数字必须为一位，比如8写成VIII，而非IIX。
    //    右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
    //加线乘千：（不考虑这种情况）
    //    在罗马数字的上方加上一条横线或者加上下标的Ⅿ，表示将这个数乘以1000，即是原数的1000倍。
    //    同理，如果上方有两条横线，即是原数的1000000（1000^{2}）倍。
    //数码限制：
    //    同一数码最多只能连续出现三次，如40不可表示为XXXX，而要表示为XL。
    //    例外：由于IV是古罗马神话主神朱庇特（即IVPITER，古罗马字母里没有J和U）的首字，因此有时用IIII代替IV。
    int romanToInt(string s) {
        return 0;
    }
};

TEST_F(LeetCodeTestFixture, RomantoInteger) {
    Solution solution;
	int integer;
	integer = solution.romanToInt("I");
    EXPECT_EQ(integer, 1);
    integer = solution.romanToInt("II");    
    EXPECT_EQ(integer, 2);
    integer = solution.romanToInt("III");	
    EXPECT_EQ(integer, 3);
    integer = solution.romanToInt("IV");	
    EXPECT_EQ(integer, 4);
    integer = solution.romanToInt("V");	    
    EXPECT_EQ(integer, 5);
    integer = solution.romanToInt("VI");	
    EXPECT_EQ(integer, 6);
    integer = solution.romanToInt("VII");	
    EXPECT_EQ(integer, 7);
    integer = solution.romanToInt("VIII");	
    EXPECT_EQ(integer, 8);
    integer = solution.romanToInt("IX");	
    EXPECT_EQ(integer, 9);
    integer = solution.romanToInt("X");	    
    EXPECT_EQ(integer, 10);
    integer = solution.romanToInt("XI");	
    EXPECT_EQ(integer, 11);
    integer = solution.romanToInt("XII");	
    EXPECT_EQ(integer, 12);
    integer = solution.romanToInt("XIII");	
    EXPECT_EQ(integer, 13);
    integer = solution.romanToInt("XIV");	
    EXPECT_EQ(integer, 14);
    integer = solution.romanToInt("XV");	
    EXPECT_EQ(integer, 15);
    integer = solution.romanToInt("XVI");	
    EXPECT_EQ(integer, 16);
    integer = solution.romanToInt("XVII");	
    EXPECT_EQ(integer, 17);
    integer = solution.romanToInt("XVIII");	
    EXPECT_EQ(integer, 18);
    integer = solution.romanToInt("XIX");	
    EXPECT_EQ(integer, 19);
    integer = solution.romanToInt("XX");	
    EXPECT_EQ(integer, 20);
    integer = solution.romanToInt("XXX");	
    EXPECT_EQ(integer, 30);
    integer = solution.romanToInt("XL");	
    EXPECT_EQ(integer, 40);
    integer = solution.romanToInt("L");	    
    EXPECT_EQ(integer, 50);
    integer = solution.romanToInt("LX");	
    EXPECT_EQ(integer, 60);
    integer = solution.romanToInt("LXX");	
    EXPECT_EQ(integer, 70);
    integer = solution.romanToInt("LXXX");	
    EXPECT_EQ(integer, 80);
    integer = solution.romanToInt("XC");	
    EXPECT_EQ(integer, 90);
    integer = solution.romanToInt("XCIX");	
    EXPECT_EQ(integer, 99);
    integer = solution.romanToInt("C");	    
    EXPECT_EQ(integer, 100);
    integer = solution.romanToInt("CI");	
    EXPECT_EQ(integer, 101);
    integer = solution.romanToInt("CII");	
    EXPECT_EQ(integer, 102);
    integer = solution.romanToInt("CXCIX");	
    EXPECT_EQ(integer, 199);
    integer = solution.romanToInt("CC");	
    EXPECT_EQ(integer, 200);
    integer = solution.romanToInt("CCC");	
    EXPECT_EQ(integer, 300);
    integer = solution.romanToInt("CD");	
    EXPECT_EQ(integer, 400);
    integer = solution.romanToInt("D");	    
    EXPECT_EQ(integer, 500);
    integer = solution.romanToInt("DC");	
    EXPECT_EQ(integer, 600);
    integer = solution.romanToInt("DCCC");	
    EXPECT_EQ(integer, 800);
    integer = solution.romanToInt("CM");	
    EXPECT_EQ(integer, 900);
    integer = solution.romanToInt("M");	    
    EXPECT_EQ(integer, 1000);
    integer = solution.romanToInt("MCD");	
    EXPECT_EQ(integer, 1400);
    integer = solution.romanToInt("MCDXXXVII");	
    EXPECT_EQ(integer, 1437);
    integer = solution.romanToInt("MD");	
    EXPECT_EQ(integer, 1500);
    integer = solution.romanToInt("MDCCC");	
    EXPECT_EQ(integer, 1800);
    integer = solution.romanToInt("MDCCCLXXX");	
    EXPECT_EQ(integer, 1880);
    integer = solution.romanToInt("MCM");	
    EXPECT_EQ(integer, 1900);
    integer = solution.romanToInt("MM");	
    EXPECT_EQ(integer, 2000);
    integer = solution.romanToInt("MMM");	
    EXPECT_EQ(integer, 3000);
    integer = solution.romanToInt("MMMCCCXXXIII");	
    EXPECT_EQ(integer, 3333);
    integer = solution.romanToInt("MV");	
}
