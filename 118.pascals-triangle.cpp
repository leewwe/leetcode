/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (47.58%)
 * Likes:    826
 * Dislikes: 83
 * Total Accepted:    280.9K
 * Total Submissions: 590.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;

        for(int i = 0; i < numRows; ++i){
            if(i == 0){
                tri.push_back(vector<int>{1});
            }
            else if(i == 1){
                tri.push_back(vector<int>{1,1});
            }
            else{
                tri.push_back(vector<int>{1});
                for(auto j = 1; j < tri[i - 1].size(); ++j) {
                    tri[i].push_back(tri[i - 1][j - 1] + tri[i - 1][j]);
                }
                tri[i].push_back(1);
            }
        }
        return tri;
    }
};

