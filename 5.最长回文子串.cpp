/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.02%)
 * Likes:    1892
 * Dislikes: 0
 * Total Accepted:    211.1K
 * Total Submissions: 727.2K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 动态规划，官方解答，注意不是子序列，是子串，所以动态规划的子结构没算法导论中的那么复杂
    /* 递推公式

                ⎧true,s[i,j]是回文串

        P(i,j)= ⎨
                ⎩false,s[i,j]不是回文串

        P(i,j)=(P(i+1,j−1)&&S[i]==S[j])
    */
    // 根据子字符串的长度计算，没有办法优化空间复杂度，因为是斜着对角进行计算的
    // string longestPalindrome(const string& s) {
    //     int n = s.size();
    //     vector<vector<bool>> dp(n, vector<bool>(n, false)); //定义动态规划数组

    //     // 初始化基础情况情况
    //     int start = 0; //回文串起始位置
    //     int len = 1; //回文串最大长度
    //     for (int i = 0; i < n - 1; ++i) {
    //         dp[i][i] = true;
    //         if (s[i] == s[i + 1]) {
    //             dp[i][i + 1] = true;
    //             start = i;
    //             len = 2;
    //         }
    //     }

    //     for (int l = 3; l <= n; ++l) { // l代表检索的长度
    //         for (int i = 0; i + l - 1 < n; ++i) { 
    //             int j = i + l - 1; // 字符串s[i,j]
    //             if (dp[i + 1][j - 1] && s[i] == s[j]) { // 只有当掐头去尾的字符串是回文子串，才判断头尾是否相等，&&的短接
    //                 dp[i][j] = true;
    //                 len = l;
    //                 start = i;
    //             }
    //         }
    //     }
    //     return s.substr(start, len);
    // }
    // 另一种写法，这个会出现Time Limit Exceeded超时
    // string longestPalindrome(const string& s) {
    //     int length = s.size();
    //     vector<vector<bool>> dp(length, vector<bool>(length, false)); //定义动态规划数组
    //     int maxLen = 0; //回文串最大长度
    //     string ret;
    //     for (int len = 1; len <= length; ++len) { //遍历所有的长度
    //         for (int start = 0; start < length; ++start) { // start和end是子字符串的首尾坐标
    //             int end = start + len - 1;
    //             if (end >= length) {//下标已经越界，结束本次循环
    //                 break;
    //             }
    //             // 这个赋值写的好
    //             dp[start][end] = (len == 1 || len == 2 || dp[start + 1][end - 1]) && s[start] == s[end]; //长度为 1 和 2 的单独判断下
    //             // 只有当len发生变化的时候才执行返回值更新
    //             if (dp[start][end] && len > maxLen) { 
    //                 ret = s.substr(start, end - start + 1);
    //             }
    //         }
    //     }
    //     return ret;
    // }

// 动态规划，可以优化空间复杂度的方法
    // 优化空间复杂度
    /* 递推公式

                ⎧true,s[i,j]是回文串

        P(i,j)= ⎨
                ⎩false,s[i,j]不是回文串

        P(i,j)=(P(i+1,j−1)&&S[i]==S[j])
        递推公式中我们可以看到，我们首先知道了 i+1才会知道 i ，所以i需要倒着遍历就行了。
        当求第 i 行的时候我们只需要第 i+1 行的信息，并且 j 的话需要 j-1 的信息，所以和之前一样 j 也需要倒叙。
    */
   // 没有优化的时候
    // string longestPalindrome(const string& s) {
    //     int length = s.size();
    //     vector<vector<bool>> dp(length, vector<bool>(length, false)); //定义动态规划数组
    //     int maxLen = 0; //回文串最大长度
    //     int maxStart = 0;
    //     for (int i = length - 1; i >= 0; --i) { //遍历所有的长度
    //         for (int j = i; j < length; ++j) { 
    //             dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]); //j - i 代表长度减去 1 ,j - i + 1 < 3 => j -i < 2 
    //             if (dp[i][j] && j - i + 1 > maxLen) {
    //                 maxLen = j - i + 1;
    //                 maxStart = i;
    //             }
    //         }
    //     }
    //     return s.substr(maxStart,maxLen);
    // }

    // // 从上面的算法看来，这是一行一行计算的
    // // 当求第 i 行的时候我们只需要第 i+1 行的信息，并且 j 的话需要 j−1 的信息，所以和之前一样 j 也需要倒叙。
    // // 简化的思考充分考虑了之前说过的倒序遍历的技巧
    // string longestPalindrome(const string& s) {
    //     int length = s.size();
    //     vector<bool> dp(length, false); //定义动态规划数组
    //     int maxLen = 0; //回文串最大长度
    //     int maxStart = 0;
    //     for (int i = length - 1; i >= 0; --i) { //遍历所有的长度
    //         for (int j = length - 1; j >= i; --j) { 
    //             dp[j] = s[i] == s[j] && (j - i < 2 || dp[j - 1]); //j - i 代表长度减去 1 ,j - i + 1 < 3 => j -i < 2 
    //             if (dp[j] && j - i + 1 > maxLen) {
    //                 maxLen = j - i + 1;
    //                 maxStart = i;
    //             }
    //         }
    //     }
    //     return s.substr(maxStart,maxLen);
    // }

// 倒置字符串后，计算最长公共子串
    // string longestPalindrome(const string& s) {
    //     if(s.size() == 0){
    //         return string("");
    //     }

    //     int n = s.size();
    //     string rev_s(s.rbegin(), s.rend());//字符串倒置
    //     vector<vector<int>> len(n,vector<int>(n,0));
        
    //     int maxLen = 0;
    //     int maxEnd = 0;
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             if (s[i] == rev_s[j]) {
    //                 if (i == 0 || j == 0) {
    //                     len[i][j] = 1;
    //                 }
    //                 else {
    //                     len[i][j] = len[i - 1][j - 1] + 1;
    //                 }
    //             }
    //             // 用于判断是否是有效的回文避免出现类似S="abc435cba"，S'="abc534cba"的错误
    //             if (len[i][j] > maxLen) {
    //                 int afterRev = n - 1 - j;
    //                 if (afterRev + len[i][j] - 1 == i) { //判断下标是否对应
    //                     maxLen = len[i][j];
    //                     maxEnd = i; //以 i 位置结尾的字符
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(maxEnd - maxLen + 1, maxLen);
    // }

    // 优化空间复杂度
    // string longestPalindrome(const string& s) {
    //     if(s.size() == 0){
    //         return string("");
    //     }
    //     int n = s.size();
    //     string rev_s(s.rbegin(), s.rend());//字符串倒置
    //     vector<int> len(n, 0);

    //     int maxLen = 0;
    //     int maxEnd = 0;
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = n - 1; j >= 0; --j) { // 这种倒着遍历是一种有效的降低空间复杂度的方法，刚好绕过了覆盖之前数据的问题
    //             if (s[i] == rev_s[j]) {
    //                 if (i == 0 || j == 0) {
    //                     len[j] = 1;
    //                 }
    //                 else {
    //                     len[j] = len[j - 1] + 1;
    //                 }
    //             }
    //             else { //之前二维数组，每次用的是不同的列，所以不用置 0 。
    //                 len[j] = 0;
    //             }
    //             if (len[j] > maxLen) {
    //                 int afterRev = n - 1 - j;
    //                 if (afterRev + len[j] - 1 == i) { //判断下标是否对应
    //                     maxLen = len[j];
    //                     maxEnd = i; //以 i 位置结尾的字符
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(maxEnd - maxLen + 1, maxLen);
    // }

// 特殊解法，扩展中心法
    // // 我们知道回文串一定是对称的，所以我们可以每次循环选择一个中心，进行左右扩展，判断左右字符是否相等即可。
    // // 由于存在奇数的字符串和偶数的字符串，所以我们需要从一个字符开始扩展，或者从两个字符之间开始扩展，所以总共有 n+n-1 个中心。
    // int expandAroundCenter(const string& s, int left, int right) {
    //     while (left >= 0 && right < s.size() && s[left] == s[right]) {
    //         --left;
    //         ++right;
    //     }
    //     // 这里 -1 是因为循环终止的条件是超出之后，所以相当于(r + 1) - (l - 1) + x，目标的答案应该是r - l + 1，所以x应该取-1
    //     return right - left - 1; 
    // }
    // string longestPalindrome(const string& s) {
    //     if (s.size() == 0) {
    //         return string("");
    //     }
    //     int start = 0, len = 0;
    //     for (int i = 0; i < s.size(); ++i) {
    //         int len1 = expandAroundCenter(s, i, i);
    //         int len2 = expandAroundCenter(s, i, i + 1);
    //         int currLen = max(len1, len2);
    //         if (currLen > len) {
    //             start = i - (currLen - 1) / 2;
    //             len = currLen;
    //         }
    //     }
    //     return s.substr(start, len);
    // }

// 特殊解法，Manacher's Algorithm 马拉车算法，这是一个专用的线性算法
    // 马拉车算法 Manacher‘s Algorithm 是用来查找一个字符串的最长回文子串的线性方法，由一个叫 Manacher 的人在 1975 年发明的，这个方法的最大贡献是在于将时间复杂度提升到了线性。
    // 这个对应于https://leetcode-cn.com/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/，
    // 做了简单的修改，RL[i]表示的回文半径是不包含中心点的，所以对应于答案中的RL[i]-1
    // 优点是不用添加特殊边界值，省一丢丢内存，缺点是在中心扩展的时候需要加边界控制
    void preProcess(const string& s, string& ret) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            ret += "#";
            ret += s[i];
        }
        ret += "#";
    }
        
    string longestPalindrome(const string& s) {
        string afterProStr;
        preProcess(s, afterProStr);
        int len = afterProStr.size();
        
        
        int maxRight = 0;           // 当前访问到的所有回文子串，所能触及的最右一个字符的位置
        int C = 0;                  // MaxRight对应的回文串的对称轴所在的位置
        int maxR = 0;               // 最大回文串的回文半径，也就是最大的回文长度
        int maxC = 0;               // maxLen对应的回文串的对称轴所在的位置
        vector<int> RL(len, 0);     // 用于记录每个i为轴的回文半径，这里是不包含中心点的回文半径，也就是回文串的长度
        for (int i = 0; i < len; ++i) {
            int i_mirror = 2 * C - i;
            if (i < maxRight) {     // 1) 当i在MaxRight的左边
                RL[i] = min(maxRight - i, RL[i_mirror]);
            }
            else {                  // 2) 当i在MaxRight的右边
                RL[i] = 0; 
            }
            // 这里做了边界控制
            while (i - RL[i] - 1 >= 0                                           // 可以把RL[i]理解为左半径,即回文串的起始位不能小于0
                && i + RL[i] + 1 < len                                          // 同上,即回文串的结束位不能大于总长
                && afterProStr[i + RL[i] + 1] == afterProStr[i - RL[i] - 1]     // 回文串特性，左右扩展，判断字符串是否相同
                ) {
                ++RL[i];
            }
        
            // 判断是否需要更新 maxRight
            if (i + RL[i] > maxRight) {
                C = i;
                maxRight = C + RL[i];
            }
            // 更新maxR, maxC
            if (maxRight - C> maxR) {
                maxC = i;
                maxR = RL[i];
            }
        }    
        //最开始讲的求原字符串下标
        int start = (maxC - RL[maxC]) / 2;
        return s.substr(start, maxR);
    }
    
    // // 这个对应于https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/
    // // 优点是不用做边界控制，缺点是浪费了一丢丢内存
    // void preProcess(const string& s, string& ret) {
        
    //     int len = s.length();
    //     if (len == 0) {
    //         ret += "^$"; // ^和$是首尾的边界控制值
    //         return;
    //     }
    //     ret = "^";
    //     for (int i = 0; i < len; i++) {
    //         ret += "#"; // #是中间的填入值
    //         ret += s[i];
    //     }
    //     ret += "#$";
    // }

    // string longestPalindrome(const string& s) {
    //     string str;
    //     preProcess(s, str);
    //     int len = str.size();

    //     int maxRight = 0;   // 当前访问到的所有回文子串，所能触及的最右一个字符的位置
    //     int C = 0;          // MaxRight对应的回文串的对称轴所在的位置
    //     int maxR = 0;       // 最大回文串的回文半径，也就是最大的回文长度
    //     int maxC = 0;       // maxLen对应的回文串的对称轴所在的位置
    //     vector<int> RL(len, 0);
    //     for (int i = 1; i < len - 1; ++i) {
    //         int i_mirror = 2 * C - i;   // 镜像点位置
    //         if (i < maxRight) {     // 1) 当i在MaxRight的左边
    //             RL[i] = min(maxRight - i, RL[i_mirror]); 
    //         }
    //         else {                  // 2) 当i刚好在MaxRight上
    //             RL[i] = 0; 
    //         }

    //         // 碰到之前讲的三种情况时候，需要利用中心扩展法
    //         // 三种情况分别是
    //         // 1-> i + RL[i_mirror] >  maxRight
    //         // 2-> i刚好在maxRight上
    //         // 3-> i_mirror碰到了原字符串的左边界
    //         // 因为添加了首尾的边界控制符，这里省去了做边界控制的麻烦
    //         while (str[i + RL[i] + 1] == str[i - RL[i] - 1]) {
    //             ++RL[i];
    //         }

    //         // 判断是否需要更新 maxRight
    //         if (i + RL[i] > maxRight) {
    //             C = i;
    //             maxRight = C + RL[i];
    //         }
    //         if (maxRight - C > maxR) {
    //             maxR = maxRight - C;
    //             maxC = i;
    //         }
    //     }
    //     //最开始讲的求原字符串下标
    //     int start = (maxC - RL[maxC]) / 2;
    //     return s.substr(start, maxR);
    // }
    
    // // 裸指针测试
    // void preProcess(const string& s, string& ret) {
        
    //     int len = s.length();
    //     if (len == 0) {
    //         ret += "^$"; // ^和$是首尾的边界控制值
    //         return;
    //     }
    //     ret = "^";
    //     for (int i = 0; i < len; i++) {
    //         ret += "#"; // #是中间的填入值
    //         ret += s[i];
    //     }
    //     ret += "#$";
    // }
    // string longestPalindrome(const string& s) {
    //     // if(s.size() == 0){
    //     //     return string("");
    //     // }
    //     string str;
    //     preProcess(s, str);
    //     int len = str.size();

    //     int maxRight = 0;   // 当前访问到的所有回文子串，所能触及的最右一个字符的位置
    //     int C = 0;          // MaxRight对应的回文串的对称轴所在的位置
    //     int maxR = 0;       // 最大回文串的回文半径，也就是最大的回文长度
    //     int maxC = 0;       // maxLen对应的回文串的对称轴所在的位置
    //     /*vector<int> RL(len, 0);*/
    //     auto RL = new int[len] {0};
    //     for (int i = 1; i < len - 1; ++i) {
    //         int i_mirror = 2 * C - i;   // 镜像点位置
    //         if (i < maxRight) {     // 1) 当i在MaxRight的左边
    //             RL[i] = min(maxRight - i, RL[i_mirror]); 
    //         }
    //         else {                  // 2) 当i刚好在MaxRight上
    //             RL[i] = 0; 
    //         }

    //         // 碰到之前讲的三种情况时候，需要利用中心扩展法
    //         // 三种情况分别是
    //         // 1-> i + RL[i_mirror] >  maxRight
    //         // 2-> i刚好在maxRight上
    //         // 3-> i_mirror碰到了原字符串的左边界
    //         // 因为添加了首尾的边界控制符，这里省去了做边界控制的麻烦
    //         while (str[i + RL[i] + 1] == str[i - RL[i] - 1]) {
    //             ++RL[i];
    //         }

    //         // 判断是否需要更新 maxRight
    //         if (i + RL[i] > maxRight) {
    //             C = i;
    //             maxRight = C + RL[i];
    //         }
    //         if (maxRight - C > maxR) {
    //             maxR = maxRight - C;
    //             maxC = i;
    //         }
    //     }
    //     //最开始讲的求原字符串下标
    //     int start = (maxC - RL[maxC]) / 2;
    //     delete[] RL;
    //     return s.substr(start, maxR);
    // }
};
// @lc code=end

