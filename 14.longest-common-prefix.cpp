/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
// // 水平扫描
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty()){
//             return string("");
//         }
//         if(strs.size() == 1){
//             return string(strs[0]);
//         }
//         string ret("");
//         auto str0 = strs[0];
//         auto str0Size = str0.size();
//         int flag = 0;
//         for (auto i = 1; i <= str0Size; ++i) {
//             auto prefix = str0.substr(0, i);
//             auto strsSize = strs.size();
//             for (auto strIndex = 1; strIndex < strsSize; ++strIndex) {
//                 auto prefixBuf = strs[strIndex].substr(0, i);
//                 if (prefixBuf != prefix) {
//                     flag = 1;
//                     continue;
//                 }
//             }
//             if (!flag) {
//                 ret = prefix;
//             }
//             else {
//                 flag = 0;
//             }
//         }
//         return ret;
//     }

// // 分治法
//     string commonPrefix(string& left, string& right) {
//         int min = fmin(left.length(), right.length());
//         for (int i = 0; i < min; ++i) {
//             if (left[i] != right[i]) {
//                 return left.substr(0, i);
//             }
//         }
//         return left.substr(0, min);
//     }
//     string longestCommonPrefix(vector<string>& strs, int l, int r) {

//         if (l == r) {
//             return strs[l];
//         }
//         else {
//             auto mid = (l + r) / 2;
//             auto lcpLeft = longestCommonPrefix(strs, l, mid);
//             auto lcpRight = longestCommonPrefix(strs, mid + 1, r);
//             return commonPrefix(lcpLeft, lcpRight);
//         }
//     }
//     string longestCommonPrefix(vector<string>& strs) {

//         if (strs.empty()) {
//             return string("");
//         }
//         return longestCommonPrefix(strs, 0, strs.size() - 1);
//     }
// 二分法
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string("");
        }
        size_t minSize = -1;
        for (auto s : strs) {
            auto tmpSize = s.size();
            if (tmpSize < minSize) {
                minSize = tmpSize;
            }
        }
        auto low = 1;
        auto high = minSize;
        while (low <= high) {
            auto mid = (low + high) / 2;
            auto str0 = strs[0];
            auto flag = 1;
            auto end = strs.end();
            for (auto iter = strs.begin() + 1; iter != end; ++iter) {
                if (iter->substr(0,mid) != str0.substr(0,mid)) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }
};

