/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.11%)
 * Likes:    734
 * Dislikes: 2140
 * Total Accepted:    429.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 手动判断
    bool isPalindrome(const string& s) {
        if (s.empty()) {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (
                (((s[i] >= '0'&& s[i] <= '9') 
                || (s[i] >= 'A' && s[i] <= 'Z')
                || (s[i] >= 'a' && s[i] <= 'z'))) 
                && 
                ((s[j] >= '0' && s[j] <= '9')
                || (s[j] >= 'A' && s[j] <= 'Z')
                || (s[j] >= 'a' && s[j] <= 'z'))) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (s[i] == s[j]) {
                        ++i;
                        --j;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else if ((s[i] >= 'A' && s[i] <= 'Z') && (s[j] >= 'A' && s[j] <= 'Z')) {
                    if (s[i] == s[j]) {
                        ++i;
                        --j;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else if((s[i] >= 'a' && s[i] <= 'z')&& (s[j] >= 'a' && s[j] <= 'z')) {
                    if (s[i] == s[j]) {
                        ++i;
                        --j;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else if(s[i] - s[j] == 'a' - 'A' || s[i] - s[j] == 'A' - 'a') {
                    ++i;
                    --j;
                }
                else {
                    return false;
                }
            }
            else if(((s[j] >= '0' && s[j] <= '9')
                || (s[j] >= 'A' && s[j] <= 'Z')
                || (s[j] >= 'a' && s[j] <= 'z'))) {
                ++i;
            }
            else {
                --j;
            }
        }
        return true;
    }

    // bool isPalindrome(const string& s) {
    //     if (s.empty()){
    //         return true;
    //     }
    //     int i = 0;
    //     int j = s.size() - 1;
    //     while (i < j){
    //         if(ispunct(s[i]) || isspace(s[i])){
    //             ++i;
    //             continue;
    //         }
    //         if(ispunct(s[j]) || isspace(s[j])){
    //             --j;
    //             continue;
    //         }
    //         if(tolower(s[i]) == tolower(s[j])){
    //             ++i;
    //             --j;
    //         }
    //         else{
    //             return false;
    //         }

    //     }
    //     return true;
    // }
};
// @lc code=end

