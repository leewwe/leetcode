/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.43%)
 * Likes:    3322
 * Dislikes: 0
 * Total Accepted:    394.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
// 暴力法
    // bool isRepeat(const string& s, const int& start, const int end) {
    //     unordered_set<char> set;
    //     for (int i = start; i < end; ++i) {
    //         if (set.count(s[i])) {
    //             return false;
    //         }
    //         set.insert(s[i]);
    //     }
    //     return true;
    // }
    // int lengthOfLongestSubstring(const string& s) {
    //     int ret = 0;
    //     for (int i = 0; i < s.size(); ++i) {
    //         for (int j = i + 1; j <= s.size(); ++j) {
    //             if (isRepeat(s, i, j)) {
    //                 ret = (j - i) > ret ? (j - i) : ret;
    //             }
    //         }
    //     }
    //     return ret;
    // }

// 滑动窗口，最快的算法
    int lengthOfLongestSubstring(string& s) {    
        int start(0), end(0), len(0), ret(0);
        while(end < s.size()){
            auto c = s[end];
            for(auto i = start; i < end; ++i){
                if(c == s[i]){
                    start = i + 1;
                    len = end - start;
                    break;
                }
            }
            ++end;
            ++len;
            ret = ret > len? ret : len;
        }
        return ret;
    }

// 滑动窗口，hash set，最慢的，因为内部还有一个循环
    // int lengthOfLongestSubstring(string& s) {
    //     int start(0), end(0), len(0), ret(0);
    //     unordered_set<char> set;
    //     // 这个while循环用于将发现重复元素之前的元素都删除掉
    //     while( start < s.size() &&  end < s.size()){
    //         auto c = s[end];
    //         while (set.find(c) != set.end()) {
    //             set.erase(s[start]);
    //             ++start;
    //         }
    //         set.insert(c);
    //         ++end;
    //         ret = ret > end - start ? ret : end - start;
    //     }
    //     return ret;
    // }

// 滑动窗口，hash map，较快，耗内存
    // int lengthOfLongestSubstring(string& s) {
    //     // s[start,end) 前面包含 后面不包含
    //     int start(0), end(0), len(0), ret(0);
    //     unordered_map<char, int> map;
    //     while (start < s.size() && end < s.size()) {
    //         auto c = s[end];
    //         // 仅当s[start,end) 中存在s[end]时更新start
    //         if (map.find(c) != map.end() && map[c] >= start) {
    //             start = map[c] + 1;
    //             len = end - start;
    //         }
    //         map[c] = end;
    //         ++end;
    //         ++len;
    //         ret = ret > len ? ret : len;
    //     }
    //     return ret;
    // }
// 桶排序，快，耗内存
    // int lengthOfLongestSubstring(string& s) {
    //     //s[start,end) 前面包含 后面不包含
    //     int start(0), end(0), len(0), ret(0);
    //     vector<int> vec(128, -1);
    //     while (start < s.size() && end < s.size()) {
    //         auto c = s[end];
    //         //仅当s[start,end) 中存在s[end]时更新start
    //         if (vec[c] >= start) {
    //             start = vec[c] + 1;
    //             len = end - start;
    //         }
    //         vec[int(c)] = end;
    //         ++end;
    //         ++len;
    //         ret = ret > len ? ret : len;
    //     }
    //     return ret;
    // }
};
// @lc code=end

