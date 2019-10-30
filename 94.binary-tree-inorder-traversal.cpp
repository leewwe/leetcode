/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
// 深度优先算法：递归
/*     void help(TreeNode* root, vector<int>& ret) {
        if (!root) {
            return;
        }
        if(root->left){
            help(root->left, ret);
        }
        ret.push_back(root->val);
        if (root->right) {
            help(root->right, ret);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> ret;
        help(root, ret);
        return ret;
    }
}; */

// 深度优先算法：使用一个栈来辅助，官方解题
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if (!root) {
    //         return vector<int>();
    //     }
    //     stack<TreeNode*> s;
    //     vector<int> ret;
    //     auto node = root;

    //     while (!s.empty() || node) {
    //     	while (node) {
    //     		s.push(node);
    //     		node = node->left;
    //     	}
    //     	node = s.top();
    //     	s.pop();
    //     	ret.push_back(node->val);
    //     	node = node->right;
    //     }
    //     return ret;
    // }
// 深度优先算法：使用一个栈来辅助
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if (!root) {
    //         return vector<int>();
    //     }
    //     stack<TreeNode*> s;
    //     vector<int> ret;
    //     auto node = root;
    //     while (!s.empty() || node) {
    //         if (node) {
    //             s.push(node);
    //             node = node->left;
    //         }
    //         else {
    //             node = s.top();
    //             s.pop();
    //             ret.push_back(node->val);
    //             node = node->right;
    //         }
    //     }
    //     return ret;
    // }
// 莫里斯遍历，线索二叉树，有一个严重的问题->莫里斯遍历会修改原来的二叉树，优势在于不需要额外的栈和递归中的栈展开，比较省空间。
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> ret;
        auto curr = root;
        while (curr) {
            if (!curr->left) {
                ret.push_back(curr->val);
                curr = curr->right;
            }
            else {
                auto pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = curr;
                auto tmpCurr = curr;
                curr = curr->left;
                tmpCurr->left = nullptr;
            }
        }
        return ret;
    }

};

