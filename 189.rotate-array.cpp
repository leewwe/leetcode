/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (31.21%)
 * Likes:    1792
 * Dislikes: 682
 * Total Accepted:    366.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */

// @lc code=start
class Solution {
public:
// 库函数，这个方法就是官方解题中的“使用额外的数组”
    // void rotate(vector<int>& nums, int k) {
    //     // 这里是为了防止在k>nums.size()的情况造成后续的非法访问
    //     if (k > nums.size()) {
    //         k %= nums.size();
    //     }
    //     vector<int> pre(nums.end() - k, nums.end());

    //     nums.insert(nums.begin(),pre.begin(), pre.end());
    //     nums.erase(nums.end() - k, nums.end());
    // }
// 环状替换
    void rotate(vector<int>& nums, int k) {
        // （因为如果 k 大于 n ，移动 k 次实际上相当于移动 k%n 次）
        if (k > nums.size()) {
            k %= nums.size();
        }

    }
};
// @lc code=end

