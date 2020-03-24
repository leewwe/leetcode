/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.40%)
 * Likes:    384
 * Dislikes: 0
 * Total Accepted:    85K
 * Total Submissions: 195.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        int diff = abs(ret - target);
        for (int i = 0; i < nums.size() - 2; ++i) {
            int L = i + 1;
            int R = nums.size() - 1;
            while (L < R) {
                int n_L = nums[L];
                int n_R = nums[R];
                int sum = nums[i] + n_L + n_R;
                int diff_tmp = abs(sum - target);
                if (diff_tmp == 0) return sum;
                else if (diff_tmp < diff) { 
                    ret = sum;
                    diff = diff_tmp;
                }
                if (sum < target) {
                    while (L < R && n_L == nums[++L]);
                }
                else {
                    while (L < R && n_R == nums[--R]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

