/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.37%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    65.1K
 * Total Submissions: 174.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        // 这里要注意size()函数返回的是size_t，是一个无符号数，所以在发生减法的时候会溢出，所以在函数的开头要将不可能的情况排除掉，或者在外面取一个int来存储这个值
        for (int i = 0; i < size - 3; ++i) { 
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏*/
            int min = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (min > target) break;
            /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略*/
            int max = nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3];
            if (max < target) continue;
            int n_i = nums[i];
            for (int j = i + 1; j < size - 2; ++j) { //以下代码与三数之和一样的
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int L = j + 1, R = size - 1;
                /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏，忽略*/
                min = n_i + nums[j] + nums[L] + nums[L + 1];
                if (min > target) continue;
                /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略*/
                max = n_i + nums[j] + nums[R] + nums[R - 1];
                if (max < target) continue;
                int n_j = nums[j];
                while (L < R) {
                    int n_L = nums[L];
                    int n_R = nums[R];
                    int sum = n_i + n_j + n_L + n_R;
                    if (sum < target) while (L < R && n_L == nums[++L]);
                    else if (sum > target) while (L < R && n_R == nums[--R]);
                    else {
                        result.push_back(vector<int>{n_i, n_j, n_L, n_R});
                        while (L < R && n_L == nums[++L]);
                        while (L < R && n_R == nums[--R]);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

