/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (38.53%)
 * Likes:    1090
 * Dislikes: 358
 * Total Accepted:    344.6K
 * Total Submissions: 894.4K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// 递归
    // bool hasPathSum(TreeNode* root, int sum) {
    //     if(!root){
    //         return false;
    //     }
    //     if(!root->left && !root->right){
    //         if(!(sum - root->val)){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return (hasPathSum(root->left, sum - root->val)) || 
    //     (hasPathSum(root->right, sum - root->val));
    // }
// 迭代
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        stack<pair<TreeNode*, int>> treeStack;
        treeStack.push({root, sum-root->val});
        while(!treeStack.empty()){
            auto node = treeStack.top().first;
            auto currSum = treeStack.top().second;
            treeStack.pop();
            if(!node->left && !node->right && !currSum){
                return true;
            }
            if(node->left){
                treeStack.push({node->left, currSum - node->left->val});
            }
            if(node->right){
                treeStack.push({node->right, currSum - node->right->val});
            }
        }
        return false;
    }
};



