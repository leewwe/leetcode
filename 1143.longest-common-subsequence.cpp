/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    // void longestCommonSubsequence_aux(const string& text1, const string& text2, vector<int>& c, const int& m, const int &n) {
    //     for (int i = 1; i <= m; ++i) {
    //         int tmp = c[0];
    //         for (int j = 1; j <= n; ++j) {
    //             if (text1[i - 1] == text2[j - 1]) {
    //                 ++tmp;
    //                 std::swap(c[j], tmp);
    //             }
    //             else {
    //                 tmp = c[j];
    //                 if (c[j] < c[j - 1]) {
    //                     c[j] = c[j - 1];
    //                 }
    //             }
    //         }
    //     }
    // }

    // int longestCommonSubsequence(const string& X, const string& Y) {
    //     // 选取较短的一行作为c的度量
    //     int m = 0;
    //     int n = 0;
    //     vector<int> c;
    //     if (X.size() >= Y.size()) {
    //         m = X.size();
    //         n = Y.size();
    //         c.resize(n + 1, 0);
    //         longestCommonSubsequence_aux(X, Y, c, m, n);
    //     }
    //     else {
    //         m = Y.size();
    //         n = X.size();
    //         c.resize(n + 1, 0);
    //         longestCommonSubsequence_aux(Y, X, c, m, n);
    //     }
    //     return c[n];
    // }


    int longestCommonSubsequence(string& X, string& Y) {
        int m = 0;
        int n = 0;
        string *x_p = &X;
        string *y_p = &Y;
        if (X.size() >= Y.size()) {
            m = X.size();
            n = Y.size();
        }
        else {
            m = Y.size();
            n = X.size();
            swap(x_p, y_p);
        }
    
        auto preRow_p = new vector<int>(n + 1, 0);
        auto nowRow_p = new vector<int>(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if ((*x_p)[i - 1] == (*y_p)[j - 1]) {
                    (*nowRow_p)[j] = (*preRow_p)[j - 1] + 1;
                }
                else if ((*preRow_p)[j] >= (*nowRow_p)[j - 1]) {
                    (*nowRow_p)[j] = (*preRow_p)[j];
                }
                else {
                    (*nowRow_p)[j] = (*nowRow_p)[j - 1];
                }
            }
            swap(preRow_p, nowRow_p);
        }
        return (*preRow_p)[n];
    }
};
// @lc code=end

