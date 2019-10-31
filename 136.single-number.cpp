/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.23%)
 * Likes:    2964
 * Dislikes: 115
 * Total Accepted:    553.9K
 * Total Submissions: 895.8K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 暴力伐就不写了，时间复杂度O(n^2)
// 使用一个底层为hash的set来操作，时间复杂度O(n),空间复杂度O(n)
    // int singleNumber(vector<int>& nums) {
    //     unordered_set<int> us;
    //     for (auto c : nums) {
    //         auto res = us.emplace(c);
    //         if (!res.second) {
    //             us.erase(res.first);
    //         }
    //     }
    //     return *(us.begin());
    // }
// 数学 2∗(a+b+c)−(a+a+b+b+c)=c，时间复杂度O(n),同样使用了set，空间复杂度O(n)
    // int singleNumber(vector<int>& nums) {
    //     unordered_set<int> us;
    //     int sum2 = 0;
    //     int sum1 = 0;
    //     for (auto c : nums) {
    //         auto res = us.emplace(c);
    //         if (!res.second) {
    //             sum2 += *res.first;
    //             us.erase(res.first);
    //         }
    //         sum1 += c;
    //     }
        
    //     sum2 += *us.begin();

    //     return 2 * sum2 - sum1;
    // }
// 位操作，异或，这个是真的秀
    // int singleNumber(vector<int>& nums) {
    //     int ret = 0;
    //     for (auto c : nums) {
    //         ret ^= c;
    //     }
    //     return ret;
    // }
};
// @lc code=end

