/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.61%)
 * Likes:    921
 * Dislikes: 0
 * Total Accepted:    210.9K
 * Total Submissions: 575.8K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
class Solution {
public:
// 对整个string数组按照长度排序，然后遍历，水平扫描，最坏情况是O(m*log(n))，m是最短字符串长度，n是字符串的个数
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        // 按照string长度排序，按最小的比较 
        sort(strs.begin(), strs.end(), [](const string& lrs, const string& rhs) {return lrs.size() < rhs.size() ? true : false; });
        string ret;
        for (int col = 0; col < strs[0].size(); ++col) {
            int row = 0;
            bool flag = true;
            while (row < strs.size()) {
                if (strs[row][col] != strs[0][col]) {
                    flag = false;
                    break;
                }
                ++row;
            }
            if (!flag) {
                break;
            }
            ret += strs[0][col];
        }
        return ret;
    }

// 分治法，O(m*log(n))
    // string commonPrefix(string& left, string& right) {
    //     int min = fmin(left.length(), right.length());
    //     for (int i = 0; i < min; ++i) {
    //         if (left[i] != right[i]) {
    //             return left.substr(0, i);
    //         }
    //     }
    //     return left.substr(0, min);
    // }
    // string longestCommonPrefix(vector<string>& strs, int l, int r) {

    //     if (l == r) {
    //         return strs[l];
    //     }
    //     else {
    //         auto mid = (l + r) / 2;
    //         auto lcpLeft = longestCommonPrefix(strs, l, mid);
    //         auto lcpRight = longestCommonPrefix(strs, mid + 1, r);
    //         return commonPrefix(lcpLeft, lcpRight);
    //     }
    // }
    // string longestCommonPrefix(vector<string>& strs) {

    //     if (strs.empty()) {
    //         return string("");
    //     }
    //     return longestCommonPrefix(strs, 0, strs.size() - 1);
    // }
// 二分法，O(n*log(m))
    // string longestCommonPrefix(vector<string>& strs) {
    //     if (strs.empty()) {
    //         return string("");
    //     }
    //     size_t minSize = -1;
    //     for (auto s : strs) {
    //         auto tmpSize = s.size();
    //         if (tmpSize < minSize) {
    //             minSize = tmpSize;
    //         }
    //     }
    //     auto low = 1; // low取1的原因是不需要在比较第一个字符串了，因为我们的取样是从第一个里取的
    //     auto high = minSize;
    //     while (low <= high) {
    //         auto mid = (low + high) / 2;
    //         auto str0 = strs[0];
    //         bool flag = true;
    //         for (auto iter = strs.begin() + 1; iter != strs.end(); ++iter) {
    //             if (iter->substr(0,mid) != str0.substr(0,mid)) {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if (!flag) {
    //             high = mid - 1;
    //         }
    //         else {
    //             low = mid + 1;
    //         }
    //     }
    //     return strs[0].substr(0, (low + high) / 2);
    // }
};
// @lc code=end

