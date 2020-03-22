/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.22%)
 * Likes:    973
 * Dislikes: 0
 * Total Accepted:    277.6K
 * Total Submissions: 485.2K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
// 偷奸的写法，用了翻转的结论
    // int reverse(int x) {
    //     int rev = 0;
    //     while (x != 0) {
    //         int pop = x % 10;
    //         x /= 10;
    //         //判断是否正溢出 1、大于号的情况 2、等于号的情况pop>7
    //         if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
    //         //判断是否负溢出 1、小于号的情况 2、等于号的情况pop<-8
    //         if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
    //         rev = rev * 10 + pop;
    //     }
    //     return rev;
    // }
    // bool isPalindrome(int x) {
    //     if(x < 0){
    //         return false;
    //     }
    //     if(x == reverse(x)){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }

// 官方解题，只翻转一半的数字
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int rev = 0;
        while(x > rev){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。

        return x == rev || x == rev / 10; 
    }
};
// @lc code=end

