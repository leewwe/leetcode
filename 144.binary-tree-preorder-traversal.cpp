/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
// 根左右
class Solution {
public:
// 深度优先算法，递归
    // void help(TreeNode* root, vector<int>& ret) {
    //     if (!root) {
    //         return;
    //     }
    //     ret.push_back(root->val);
    //     if(root->left) {
    //         help(root->left, ret);
    //     }
    //     if (root->right) {
    //         help(root->right, ret);
    //     }
    // }



    // vector<int> preorderTraversal(TreeNode* root) {
    //     if (!root) {
    //         return vector<int>();
    //     }
    //     vector<int> ret;
    //     help(root, ret);
    //     return ret;
    // }

// 深度优先算法，栈
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if (!root) {
    //         return vector<int>();
    //     } 
    //     vector<int> ret;
    //     stack<TreeNode*> s;
    //     s.push(root);
    //     while (!s.empty()) {
    //         auto r = s.top();
    //         s.pop();
    //         ret.push_back(r->val);
    //         if (r->right) {
    //             s.push(r->right);
    //         }
    //         if (r->left) {
    //             s.push(r->left);
    //         }
    //     }
    //     return ret;
    // }
// 莫里斯遍历，线索二叉树，有一个严重的问题->莫里斯遍历会修改原来的二叉树，优势在于不需要额外的栈和递归中的栈展开，比较省空间。
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        auto node = root;
        vector<int> ret;
        while (node) {
            if (!node->left) {
                ret.push_back(node->val);
                node = node->right;
            }
            else {
                auto predecessor = node->left;
                while (predecessor->right && predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right) {
                    ret.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                }
                else {
                    predecessor->right = nullptr;
                    node = node->right;
                }
            }
        }
        return ret;
    }
};

