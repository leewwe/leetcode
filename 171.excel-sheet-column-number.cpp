/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(const string& s) {
        int sum = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            sum += (s[i] - 'A' + 1) * pow(26, s.size() - 1 - i);
        }
        return sum;
    }

    // int titleToNumber(const string& s) {
    //     int sum = 0;

    //     for (int i = 0; i < s.size(); ++i) {
    //         sum *= 26;
    //         sum += s[i] - 'A' + 1;
    //     }
    //     return sum;
    // }
};
// @lc code=end

