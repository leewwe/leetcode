/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(const uint32_t& n) {
        uint32_t ret = 0;
        for (int i = 0; i < 16; ++i) {
            uint32_t pre = (0x80000000 >> i)& n;
            uint32_t suf = (1 << i) & n;
            ret |= pre >> (32 - 2 * i - 1);
            ret |= (suf << (32 - 2 * i - 1));
        }
        return ret;
    }
};
// @lc code=end

