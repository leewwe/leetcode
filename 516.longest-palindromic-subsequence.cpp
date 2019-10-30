/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
// 算法导论的解法
    // int longestPalindromeSubseq(const string& s) {
    //     int n = s.size();
    //     vector<vector<int>> p(n, vector<int>(n, 0));

    //     // 初始化数组
    //     for (int i = 0; i < n - 1; ++i) {
    //         p[i][i] = 1;
    //         if (s[i] == s[i + 1]) {
    //             p[i][i + 1] = 2;
    //         }
    //         else {
    //             p[i][i + 1] = 1;
    //         }
    //     }
    //     p[n - 1][n - 1] = 1;

    //     // 计算
    //     for (int i = n - 3; i >= 0; --i) {
    //         for (int j = i + 2; j < n; ++j) {
    //             if (s[i] == s[j]) {
    //                 p[i][j] = p[i + 1][j - 1] + 2;
    //             }
    //             else if (p[i + 1][j] >= p[i][j - 1]) {
    //                 p[i][j] = p[i + 1][j];
    //             }
    //             else {
    //                 p[i][j] = p[i][j - 1];
    //             }
    //         }
    //     }
    //     return p[0][n - 1];
    // }

// leetcode中文论坛的解法
    // int longestPalindromeSubseq(const string& s) {
    //     int n = s.size();
    //     vector<vector<int>> p(n, vector<int>(n, 0));
    //     // 计算
    //     for (int i = n - 1; i >= 0; --i) {
    //         p[i][i] = 1;
    //         for (int j = i + 1; j < n; ++j) {
    //             if (s[i] == s[j]) {
    //                 p[i][j] = p[i + 1][j - 1] + 2;
    //             }
    //             else if (p[i + 1][j] >= p[i][j - 1]) {
    //                 p[i][j] = p[i + 1][j];
    //             }
    //             else {
    //                 p[i][j] = p[i][j - 1];
    //             }
    //         }
    //     }

    //     return p[0][n - 1];
    // }

// 优化过的解法，减少空间使用，只是用两行的写法
    // int longestPalindromeSubseq(const string& s) {
    //     int n = s.size();
    //     // 使用两个指针
    //     auto preRow_p = new vector<int>(n, 0);
    //     auto nowRow_p = new vector<int>(n, 0);

    //     for (int i = n - 1; i >= 0; --i) {
    //         (*nowRow_p)[i] = 1;
    //         for (int j = i + 1; j < n; ++j) {
    //             if (s[i] == s[j]) {
    //                 (*nowRow_p)[j] = (*preRow_p)[j - 1] + 2;
    //             }
    //             else if ((*preRow_p)[j] >= (*nowRow_p)[j - 1]) {
    //                 (*nowRow_p)[j] = (*preRow_p)[j];
    //             }
    //             else {
    //                 (*nowRow_p)[j] = (*nowRow_p)[j - 1];
    //             }
    //         }
    //         // 交换指针而不是交换整个vector
    //         swap(preRow_p, nowRow_p);
    //     }
    //     // 返回的时候注意，返回的是pre而不是now，因为最后做了一次交换
    //     return (*preRow_p)[n - 1];
    // }

// 只是用一行的写法，最终优化版本
    int longestPalindromeSubseq(const string& s) {
        int n = s.size();
        vector<int> p(n, 0);

        // 计算
        int tmp = 0;
        for (int i = n - 1; i >= 0; --i) {
            p[i] = 1;
            int p_tmp = 0;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    int tmp = p_tmp;
                    p_tmp = p[j];
                    p[j] = tmp + 2;
                }
                else if (p[j] < p[j - 1]) {
                    p_tmp = p[j];
                    p[j] = p[j - 1];
                }
                else {
                    p_tmp = p[j];
                }
            }
        }
        return p[n - 1];
    }
};
// @lc code=end

