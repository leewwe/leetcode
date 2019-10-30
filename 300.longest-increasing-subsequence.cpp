/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
// // 二分查找
//     int find_pos(int x, const vector<int>& S, int ls) {
//         int left = 0;
//         int right = ls;
//         int rBound = right;
//         while (left < right) {
//             int mid = (left + right) / 2;
//             if (S[mid] >= x) {
//                 right = mid;
//             }
//             else {
//                 left = mid + 1;
//             }
//         }
//         if(right >= rBound){		// 检查是否越界
//             return right;
//         }
//         else {
//             if (S[right] >= x) {
//                 return right;
//             }
//             else {
//                 return right + 1;
//             }
//         }
//     }


// // 参数x：输入序列
// // 返回值：LMIS的长度

//     int lengthOfLIS(vector<int>& nums) {
//         if(nums.empty()){
//             return 0;
//         }
//         auto n = nums.size();
//         vector<int> S(n, 0);
//         vector<int> e(n, 0);
//         S[0] = nums[0];
//         e[0] = 1;

//         int ls = 1;
//         for (int i = 1; i < n; ++i) {
//             int pos = find_pos(nums[i], S, ls);	// 返回的是S中的位置
//             S[pos] = nums[i];                      // 存储相应的距离
//             e[i] = ++pos;						// 存储长度，并将pos转换为长度
//             if (pos > ls) {
//                 ls = pos;
//             }
//         }
//         return ls;
//     }

    // int lengthOfLIS(vector<int>& nums){
    //     if(nums.empty()){
    //         return 0;
    //     }
    //     vector<int> res{nums[0]};
    //     int k = 0;
    //     for(int i = 1; i < nums.size(); ++i){
    //         auto num = nums[i];
    //         if(num > res[k]){
    //             res.push_back(num);
    //             ++k;
    //             continue;
    //         }
    //         int p = 0;
    //         int q = k;
    //         while(p < q){
    //             int m = (p + q) / 2;
    //             if(res[m] < num){
    //                 p = m + 1;
    //             }
    //             else{
    //                 q = m;
    //             }
    //         }
    //         res[p] = num;
    //     }
    //     return res.size();
    // }

    int lengthOfLIS(vector<int>& nums){
        vector<int> res;
        int k = -1;
        for(auto num : nums) {
            if(res.empty() || num > res[k]){
                res.push_back(num);
                ++k;
                continue;
            }
            int i = 0;
            int j = res.size() - 1;
            while(i < j) {
                int m = (i + j) / 2;
                if(res[m] < num){
                    i = m + 1;
                }
                else{
                    j = m;
                }
            }
            res[i] = num;
        }
        return res.size();
    }

};
// @lc code=end

