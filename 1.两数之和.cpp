/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.46%)
 * Likes:    13943
 * Dislikes: 510
 * Total Accepted:    2.7M
 * Total Submissions: 5.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
// 暴力求解法，
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ret;
    //     auto size = nums.size();
    //     for(auto i = 0; i < size; ++i ){
    //         auto tmp1 = nums[i];
    //         for(auto j = i + 1; j < size; ++j){
    //             auto sum = tmp1 + nums[j];
    //             if(sum == target){
    //                 ret.push_back(i);
    //                 ret.push_back(j);
    //                 return ret;
    //             }
    //             else{
    //                 continue;
    //             }
    //         }
    //     }
    //     return ret;
    // }
// 哈希表，先填入哈希表，然后查找
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ret;
    //     unordered_map<int,int> map;
    //     for(int i = 0; i < nums.size(); ++i){
    //         map[nums[i]] = i;
    //     }
    //     for(int i = 0; i < nums.size(); ++i){
    //         auto ele = target - nums[i];
    //         if(map.count(ele) && map[ele] != i){
    //             return {i,map[ele]};
    //         }
    //     }

    //     return ret;
    // }
// 哈希表，只填入一次
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); ++i){
            auto ele = target - nums[i];
            if(map.count(ele)){
                return {map[ele],i};
            }
            map[nums[i]] = i;
        }

        return ret;
    }
};
// @lc code=end

