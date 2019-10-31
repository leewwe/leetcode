/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (44.91%)
 * Likes:    538
 * Dislikes: 177
 * Total Accepted:    221.4K
 * Total Submissions: 492.8K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> even{1};
        vector<int> odd{1,1};
        if(rowIndex == 0){
            return even;
        }
        if(rowIndex == 1){
            return odd;
        }
        for(int i = 2; i <= rowIndex; i++){
            // 计算奇数行
            if((i%2)){
                odd.clear();
                odd.push_back(1);
                for(int j = 1; j < even.size(); ++j){
                    odd.push_back(even[j - 1] + even[j]);
                }
                odd.push_back(1);
                continue;
            }
            // 计算偶数行
            even.clear();
            even.push_back(1);
            for(int j = 1; j < odd.size(); ++j){
                even.push_back(odd[j - 1] + odd[j]);
            }
            even.push_back(1);
        }
        return (rowIndex % 2) ? odd : even;
    }
};

