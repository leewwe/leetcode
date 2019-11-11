/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
// 这是一道数学问题，数论算法
    int trailingZeroes(int& n) {
        int cnt = 0;
        while(n){
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
// @lc code=end

