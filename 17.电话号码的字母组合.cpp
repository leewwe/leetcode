/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.90%)
 * Likes:    623
 * Dislikes: 0
 * Total Accepted:    91.8K
 * Total Submissions: 173.4K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
/* N叉树的遍历，据说这是一道回溯算法 */
// public:
// 
//     void letterCombinations_aux(const int h, const string& d, const string mid, vector<string>& ret) {
//         if (h == d.size() - 1) {
//             for (auto c : numMap[d[h]]) {
//                 ret.push_back(mid + c);
//             }
//             return;
//         }

//         for (auto c : numMap[d[h]]) {
//             letterCombinations_aux(h + 1, d, mid + c, ret);
//         }
//     }

//     // 树的遍历，完全n叉树的遍历
//     vector<string> letterCombinations(const string& digits) {
//         if (digits.empty()) {
//             return {};
//         }
//         vector<string> ret;
//         letterCombinations_aux(0, digits, "", ret);
//         return ret;
//     }
// private:
//     unordered_map<char, string> numMap{
//         { '2', "abc"},
//         { '3', "def" },
//         { '4', "ghi" },
//         { '5', "jkl" },
//         { '6', "mno" },
//         { '7', "pqrs" },
//         { '8', "tuv" },
//         { '9', "wxyz" }
//     };
/* 改进空间复杂度，不适用hash表，而是直接映射 */
public:
    void letterCombinations_aux(const int h, const string& d, const string mid, vector<string>& ret) {
        if (h == d.size() - 1) {
            for (auto c : numMap[d[h] - '0']) {
                ret.push_back(mid + c);
            }
            return;
        }

        for (auto c : numMap[d[h] - '0']) {
            letterCombinations_aux(h + 1, d, mid + c, ret);
        }
    }

    // 树的遍历，完全n叉树的遍历
    vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> ret;
        letterCombinations_aux(0, digits, "", ret);
        return ret;
    }
private:
    // vector<string> numMap{// 改成C数组后就更快了
    const string numMap[10]{    
        "",         // 0
        "",         // 1
        "abc",      // 2
        "def",      // 3
        "ghi",      // 4
        "jkl",      // 5
        "mno",      // 6
        "pqrs",     // 7
        "tuv",      // 8
        "wxyz"      // 9
    };
};
// @lc code=end

