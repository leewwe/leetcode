/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:

// CLRS原版程序，需要使用矩阵，O(mn)
    // int minDistance(const string& word1, const string& word2) {
    //     int m = word1.size();
    //     int n = word2.size();

    //     vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    //     for (int i = 0; i <= m; ++i) {
    //         c[i][0] = i;
    //     }
    //     for (int j = 0; j <= n; ++j) {
    //         c[0][j] = j;
    //     }


    //     for (int i = 1; i <= m; ++i) {
    //         for (int j = 1; j <= n; ++j) {
    //             c[i][j] = INT_MAX;

    //             // copy
    //             int cost = c[i - 1][j - 1];
    //             if (word1[i - 1] == word2[j - 1]) {
    //                 c[i][j] = cost;
    //             }

    //             // replace
    //             cost = c[i - 1][j - 1] + 1;
    //             if (word1[i - 1] != word2[j - 1] && cost < c[i][j]) {
    //                 c[i][j] = cost;
    //             }

    //             // delete
    //             cost = c[i - 1][j] + 1;
    //             if (cost < c[i][j]) {
    //                 c[i][j] = cost;
    //             }

    //             // insert
    //             cost = c[i][j - 1] + 1;
    //             if (cost < c[i][j]) {
    //                 c[i][j] = cost;
    //             }
    //         }
    //     }
    //     return c[m][n];
    // }

// 逻辑简单版，原理和原版的程序一样，都需要使用矩阵，O(mn)
    // int minDistance(const string& word1, const string& word2) {
    //     int m = word1.size();
    //     int n = word2.size();

    //     vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    //     for (int i = 0; i <= m; ++i) {
    //         c[i][0] = i;
    //     }
    //     for (int j = 0; j <= n; ++j) {
    //         c[0][j] = j;
    //     }


    //     for (int i = 1; i <= m; ++i) {
    //         for (int j = 1; j <= n; ++j) {
    //             c[i][j] = INT_MAX;

    //             // copy/skip
    //             if (word1[i - 1] == word2[j - 1]) {
    //                 c[i][j] = c[i - 1][j - 1];
    //                 continue;
    //             }
    //             // 其余三种情况 替换 删除 插入
    //             else {
    //                 c[i][j] = min(c[i - 1][j - 1] + 1, min(c[i - 1][j] + 1, c[i][j - 1] + 1));
    //             }
    //         }
    //     }
    //     return c[m][n];
    // }
// 优化空间复杂度，只是用一行就可以O(min(m,n)))
    int minDistance(const string& word1, const string& word2) {
        auto p1 = &word1;
        auto p2 = &word2;

        if (word1.size() < word2.size()) {
            swap(p1, p2);
        }

        vector<int> c(p2->size() + 1, 0);

        for (int j = 0; j <= p2->size(); ++j) {
            c[j] = j;
        }

        for (int i = 1; i <= p1->size(); ++i) {
            c[0] = i;
            int tmp = i - 1;
            for (int j = 1; j <= p2->size(); ++j) {			
                // copy/skip
                int c_j = c[j];
                if ((*p1)[i - 1] == (*p2)[j - 1]) {
                    c[j] = tmp;
                }
                // 其余三种情况 替换 删除 插入
                else {
                    c[j] = min(tmp + 1, min(c[j] + 1, c[j - 1] + 1));
                }
                tmp = c_j;
            }
        }
        return c.back();
    }
};
// @lc code=end

