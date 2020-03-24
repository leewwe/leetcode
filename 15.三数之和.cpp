/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.07%)
 * Likes:    1921
 * Dislikes: 0
 * Total Accepted:    181.9K
 * Total Submissions: 696.3K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 排序，双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        int n_i = nums[i];
        if (n_i > 0) break;
        if (i > 0 && n_i == nums[i - 1]) continue;
        int L = i + 1;
        int R = nums.size() - 1;
        while (L < R) {
            int n_L = nums[L];
            int n_R = nums[R];
            int sum = n_i + n_L + n_R;
            if (sum < 0) {
                while (L < R && n_L == nums[++L]);
            }
            else if (sum > 0) {
                while (L < R && n_R == nums[--R]);
            }
            else {
                ret.push_back({ nums[i] , nums[L] , nums[R] });
                while (L < R && n_L == nums[++L]);
                while (L < R && n_R == nums[--R]);
            }
        }
    }
    return ret;
    }

};
// @lc code=end

