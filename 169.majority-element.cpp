/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start

// 所有的方法都没有hash表跑得快，😂，库函数还是吊啊
class Solution {
public:
// hash表
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (auto a : nums) {
            ++m[a];
        }
        int max = 0;
        int ret = nums[0];
        for (auto a : m) {
            if (a.second > max) {
                max = a.second;
                ret = a.first;
            }
        }
        return ret;
    }
// 排序，如果所有数字被单调递增或者单调递减的顺序排了序，那么众数的下标为 ⌊n/2⌋
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end(),less<int>());
    //     return nums[nums.size()/2];
    // }
// 分治，如果我们知道数组左边一半和右边一半的众数，我们就可以用线性时间知道全局的众数是哪个。
    // int majorityElement(vector<int>& nums) {
    //     return majorityElement_rec(nums, 0, nums.size() - 1);
    // }

    // private:
    // int countInRange(const vector<int>& nums, const int& num, const int& low, const int& high){
    //     int cnt = 0;
    //     for(int i = low; i <= high; ++i){
    //         if(nums[i] == num){
    //             ++cnt;
    //         }
    //     }
    //     return cnt;
    // }

    // int majorityElement_rec(const vector<int>& nums, const int& low, const int& high){
    //     // base case; the only element in an array of size 1 is the majority
    //     // element.
    //     if(low == high){
    //         return nums[low];
    //     }
    //     // recurse on left and right halves of this slice.
    //     int mid = (low + high) / 2;
    //     int left = majorityElement_rec(nums, low, mid);
    //     int right = majorityElement_rec(nums, mid + 1, high);
    //     // if the two halves agree on the majority element, return it.
    //     if(left == right){
    //         return left;
    //     }
    //     // otherwise, count each element and return the "winner".
    //     int leftCnt = countInRange(nums, left, low, high);
    //     int rightCnt = countInRange(nums, right, low, high);
    //     return leftCnt > rightCnt ? left : right;
    // }
// Boyer-Moore 投票算法,如果我们把众数记为 +1 ，把其他数记为 −1 ，将它们全部加起来，显然和大于 0 ，从结果本身我们可以看出众数比其他数多。
    /* 
    本质上， Boyer-Moore 算法就是找 nums 的一个后缀 suf ，其中 suf[0] 就是后缀中的众数。我们维护一个计数器，
    如果遇到一个我们目前的候选众数，就将计数器加一，否则减一。只要计数器等于 0 ，我们就将 nums 中之前访问的数字
    全部 忘记 ，并把下一个数字当做候选的众数。直观上这个算法不是特别明显为何是对的，我们先看下面这个例子（竖线用
    来划分每次计数器归零的情况）
    */
    // int majorityElement(vector<int>& nums) {
    //     int cnt = 1;
    //     int candidate = nums[0];
    //     for(int i = 1; i < nums.size(); ++i){
    //         if(!cnt){
    //             candidate = nums[i];
    //         }
    //         cnt += candidate == nums[i] ? 1 : -1;
    //     }
    //     return candidate;
    // }
};
// @lc code=end

