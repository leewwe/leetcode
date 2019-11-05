/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
// 普通的借位操作
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        string ret;
        while (n) {
            int quo = n % 26;
            if (quo == 0) {
                --n;//借位操作，在余数为0的时候需要向之高位借位
                ret.insert(ret.begin(), 'Z');	
            }
            else {
                ret.insert(ret.begin(), quo + 'A' - 1);
            }
            n /= 26;
        }
        return ret;
    }
// 对于Z我们需要减一，对于A-Y也需要减一，如果我们可以减这两种减一统一起来事情就变得简单了。
// 所以我们可以考虑在取余之前就整体减一。我们可以证明对于26的N倍（num%26 = N），我们整体减
// 一在取余就会得到(num-1)%26 = N-1余25，所以25直接加上A的ASCII码就得Z，所以对于Z而言是可
// 以提前减一的。对于A-Y而言num%26 = N余t，t属于1到25的范围。这个t减一在加上'A'的ASCII码就
// 对于与A-Y（t+'A'-1），而如果我们提前减一的话这个表达式就变成了(num-1)%26 =N余t-1;最后我
// 们的到的值就不用进行减一操作（t-1+'A'）。所以可以将Z和A-Y的操作统一起来了，提前减一，然后
// 再正常取模即可。
    // string convertToTitle(int n) {
    //     if (n <= 0) {
    //         return "";
    //     }
    //     string ret;
    //     int quo = n % 26;
    //     while (n) {
    //         --n;
    //         quo = n % 26;
    //         ret = char(quo + 'A') + ret;
    //         n /= 26;
    //     }
    //     return ret;
    // }
};
// @lc code=end

