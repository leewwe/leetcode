/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (47.13%)
 * Likes:    605
 * Dislikes: 0
 * Total Accepted:    108.2K
 * Total Submissions: 229.5K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
class Solution {
public:
// 自己写的，本质上和官方解题的解法二是一样的
    // string convert(const string& s, const int numRows) {
    //     if (numRows <= 1) {
    //         return s;
    //     }
    //     string ret;
    //     int i = 0;
    //     int mid = numRows - 2;
    //     int incr = numRows + mid;
    //     while (i < s.size()) {
    //         ret += s[i];
    //         i += incr;
    //     }

    //     i = 1;
    //     while (mid > 0) {
    //         int j = i;
    //         int midIncr = incr - mid * 2;
    //         bool isMid = true;
    //         while (j < s.size()) {
    //             ret += s[j];
    //             if (isMid) {
    //                 j += 2 * mid;
    //                 isMid = false;
    //             }
    //             else {
    //                 j += midIncr;
    //                 isMid = true;
    //             }
    //         }
    //         ++i;
    //         --mid;
    //     }
    //     i = numRows - 1;
    //     while (i < s.size()) {
    //         ret += s[i];
    //         i += incr;
    //     }
    //     return ret;
    // }

// 官方解题，解法二，代码漂亮一点
    // string convert(string s, int numRows) {

    //     if (numRows == 1) return s;

    //     string ret;
    //     int n = s.size();
    //     int cycleLen = 2 * numRows - 2;

    //     for (int i = 0; i < numRows; i++) {
    //         for (int j = 0; j + i < n; j += cycleLen) {
    //             ret += s[j + i];
    //             if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
    //                 ret += s[j + cycleLen - i];
    //         }
    //     }
    //     return ret;
    // }
// 官方解题，使用行数个string做缓冲区，直观上来看就是在画N字
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
// @lc code=end

