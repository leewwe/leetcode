/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (44.53%)
 * Likes:    579
 * Dislikes: 451
 * Total Accepted:    302.4K
 * Total Submissions: 656K
 * Testcase Example:  '00000000000000000000000000001011'
 *
 * Write a function that takes an unsigned integer and return the number of '1'
 * bits it has (also known as the Hamming weight).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 00000000000000000000000000001011
 * Output: 3
 * Explanation: The input binary string 00000000000000000000000000001011 has a
 * total of three '1' bits.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 00000000000000000000000010000000
 * Output: 1
 * Explanation: The input binary string 00000000000000000000000010000000 has a
 * total of one '1' bit.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 11111111111111111111111111111101
 * Output: 31
 * Explanation: The input binary string 11111111111111111111111111111101 has a
 * total of thirty one '1' bits.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, the input will be given as signed integer type and should not
 * affect your implementation, as the internal binary representation of the
 * integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 3 above the input represents the signed
 * integer -3.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 * 
 */

// @lc code=start
class Solution {
public:
// 方法 1：循环和位移动
    // int hammingWeight(uint32_t n) {
    //     char cnt = 0;
    //     for(int i = 0; i < 32; ++i){
    //         cnt += n & (1 << i) ? 1 : 0;
    //     }    
    //     return cnt;
    // }
// 方法 2：位操作的小技巧
    int hammingWeight(const uint32_t& n){
        char cnt = 0;
        uint32_t n_buf = n;
        while(n_buf != 0){
            ++cnt;
            n_buf &= n_buf - 1;
        }
        return cnt;
    }
};
// @lc code=end

