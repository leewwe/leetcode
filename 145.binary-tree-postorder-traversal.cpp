/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
// 深度优先：递归
    // void help(TreeNode* root, vector<int>& ret) {
    //     if (!root) {
    //         return;
    //     }
    //     help(root->left, ret);
    //     help(root->right, ret);
    //     ret.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if (!root) {
    //         return vector<int>();
    //     }
    //     vector<int> ret;
    //     help(root, ret);
    //     return ret;
    // }
// 深度优先：迭代
    // 妙啊，后序遍历是从前面insert的
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> ret;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto r = s.top();
            s.pop();
            ret.insert(ret.begin(), r->val);
            if (r->left) {
                s.push(r->left);
            }
            if (r->right) {
                s.push(r->right);
            }
        }

        return ret;
    }
};

