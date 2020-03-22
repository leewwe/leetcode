/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.13%)
 * Likes:    2311
 * Dislikes: 0
 * Total Accepted:    160.3K
 * Total Submissions: 431.6K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 两个数组归并成一个数组，O(m+n)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> vec;
    //     int i = 0, j = 0;
    //     while (i < nums1.size() || j < nums2.size()) {
    //         if (i >= nums1.size()) {
    //             while (j < nums2.size()) {
    //                 vec.push_back(nums2[j]);
    //                 ++j;
    //             }
    //         }
    //         else if (j >= nums2.size()) {
    //             while (i < nums1.size()) {
    //                 vec.push_back(nums1[i]);
    //                 ++i;
    //             }
    //         }
    //         else {
    //             if (nums1[i] < nums2[j]) {
    //                 vec.push_back(nums1[i]);
    //                 ++i;
    //             }
    //             else {
    //                 vec.push_back(nums2[j]);
    //                 ++j;
    //             }
    //         }
    //     }
    //     if (vec.size() % 2) {
    //         return vec[vec.size() / 2];
    //     }
    //     else {
    //         return (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2.0;
    //     }
    // }
// 直接找中位数的位置,O(m+n)
    /* 其实，我们不需要将两个数组真的合并，我们只需要找到中位数在哪里就可以了。

    开始的思路是写一个循环，然后里边判断是否到了中位数的位置，到了就返回结果，但这里对偶数和奇数的分类会很麻烦。当其中一个数组遍历完后，出了 for 循环对边界的判断也会分几种情况。总体来说，虽然复杂度不影响，但代码会看起来很乱。

    首先是怎么将奇数和偶数的情况合并一下。

    用 len 表示合并后数组的长度，如果是奇数，我们需要知道第 （len+1）/2 个数就可以了，如果遍历的话需要遍历 int(len/2 ) + 1 次。如果是偶数，我们需要知道第 len/2和 len/2+1 个数，也是需要遍历 len/2+1 次。所以遍历的话，奇数和偶数都是 len/2+1 次。

    返回中位数的话，奇数需要最后一次遍历的结果就可以了，偶数需要最后一次和上一次遍历的结果。所以我们用两个变量 left 和 right，right 保存当前循环的结果，在每次循环前将 right 的值赋给 left。这样在最后一次循环的时候，left 将得到 right 的值，也就是上一次循环的结果，接下来 right 更新为最后一次的结果。

    循环中该怎么写，什么时候 A 数组后移，什么时候 B 数组后移。用 aStart 和 bStart 分别表示当前指向 A 数组和 B 数组的位置。如果 aStart 还没有到最后并且此时 A 位置的数字小于 B 位置的数组，那么就可以后移了。也就是aStart＜m&&A[aStart]< B[bStart]。

    但如果 B 数组此刻已经没有数字了，继续取数字 B[ bStart ]，则会越界，所以判断下 bStart 是否大于数组长度了，这样 || 后边的就不会执行了，也就不会导致错误了，所以增加为 aStart＜m&&(bStart) >= n||A[aStart]<B[bStart]) 。 */
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int len = nums1.size() + nums2.size();
        
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     int aStart = 0;
    //     int bStart = 0;
    //     int pre = 0, curr = 0;
    //     for (int i = 0; i < len / 2 + 1; ++i) {
    //         pre = curr;
    //         // 这个if中的判断充分利用了&& 和 || 的短接特性
    //         // &&前面的条件错误，||前面的条件正确，后面的条件都不用判断了
    //         if (aStart < n && (bStart >= m || nums1[aStart] < nums2[bStart])) {
    //             curr = nums1[aStart++];
    //         }
    //         else {
    //             curr = nums2[bStart++];
    //         }
    //     }
    //     if (len & 1) {
    //         return curr;
    //     }
    //     else {
    //         return (pre + curr) / 2.0;
    //     }
        
    // }





// 寻找第k小的元素的方法，O(log(m+n))
    // 递归版本
    int getKth(vector<int>& nums1, int s1, int e1,
        vector<int>& nums2, int s2, int e2, int k) {
        
        int l1 = e1 - s1 + 1;
        int l2 = e2 - s2 + 1;
        //让 l1 的长度小于 l2，这样就能保证如果有数组空了，一定是 l1 
        if (l1 > l2) {
            // std::swap(nums1, nums2);
            // std::swap(s1, s2);
            // std::swap(e1, e2);
            // std::swap(l1, l2);
            return getKth(nums2, s2, e2, nums1, s1, e1, k);
        }
        if (l1 == 0) {
            return nums2[s2 + k - 1];
        }
        if (k == 1) {
            return min(nums2[s2], nums1[s1]);
        }

        // 确定要比较的元素的坐标
        int i = s1 + min(l1, k / 2) - 1;
        int j = s2 + min(l2, k / 2) - 1;
        if (nums1[i] > nums2[j]) {
            return getKth(nums1, s1, e1, nums2, j + 1, e2, k - (j - s2 + 1));
        }
        else {
            return getKth(nums1, i + 1, e1, nums2, s2, e2, k - (i - s1 + 1));
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        // 将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k 。
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2.0;
    }

    // 迭代版本
    // int getKth(vector<int>& nums1, int s1, int e1,
    //     vector<int>& nums2, int s2, int e2, int k) {
        
    //     int l1 = -1, l2 = -1;
    //     while (1) {
    //         l1 = e1 - s1 + 1;
    //         l2 = e2 - s2 + 1;
    //         //让 l1 的长度小于 l2，这样就能保证如果有数组空了，一定是 l1 
    //         if (l1 > l2) {
    //             // std::swap(nums1, nums2);
    //             // std::swap(s1, s2);
    //             // std::swap(e1, e2);
    //             // std::swap(l1, l2);
    //             return getKth(nums2, s2, e2, nums1, s1, e1, k);
    //         }

    //         if (l1 == 0) {
    //             return nums2[s2 + k - 1];
    //         }
    //         if (k == 1) {
    //             return min(nums2[s2], nums1[s1]);
    //         }

    //         // 确定要比较的元素的坐标
    //         int i = s1 + min(l1, k / 2) - 1;
    //         int j = s2 + min(l2, k / 2) - 1;
    //         if (nums1[i] > nums2[j]) {
    //             k -= (j - s2 + 1);
    //             s2 = j + 1;
    //         }
    //         else {
    //             k -= (i - s1 + 1);
    //             s1 = i + 1;
    //         }
    //     }
    // }

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();

    //     int left = (n + m + 1) / 2;
    //     int right = (n + m + 2) / 2;

    //     // if ((n + m) & 1) { // 奇数的情况
    //     //     return getKth(nums1, 0, n - 1, nums2, 0, m - 1, left);
    //     // }
    //     // else {
    //     //     return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2.0;
    //     // }
    //     return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2.0;
    // }

// 二分法，划分左右两部分，O(log(min(m,n)))
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    //     double ret = 0;
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     // 保证 m <= n
    //     if (n < m) {
    //         std::swap(nums1, nums2);
    //         std::swap(n, m);
    //     }
    //     // 
    //     int iMin = 0, iMax = m;
    //     while (iMin <= iMax) {
    //         int i = (iMin + iMax) / 2;
    //         int j = (m + n + 1) / 2 - i;
    //         if (j != 0 && i != m && nums2[j - 1] > nums1[i]) { // i 需要增大
    //             iMin = i + 1;
    //         }
    //         else if( i != 0 && j != n && nums1[i - 1] > nums2[j]) { // i 需要减小
    //             iMax = i - 1;
    //         }
    //         else { // 达到要求，并且将边界条件列出来单独考虑
    //             int leftMax = 0;
    //             if (i == 0) {
    //                 leftMax = nums2[j - 1];
    //             }
    //             else if(j == 0) {
    //                 leftMax = nums1[i - 1];
    //             }
    //             else {
    //                 leftMax = max(nums1[i - 1], nums2[j - 1]);
    //             }
    //             if ((m + n) & 1) { 
    //                 return leftMax; // 奇数的话不需要考虑右半部分
    //             }

    //             int rightMin = 0;
    //             if (i == m) {
    //                 rightMin = nums2[j];
    //             }
    //             else if(j == n){
    //                 rightMin = nums1[i];
    //             }
    //             else {
    //                 rightMin = min(nums1[i], nums2[j]);
    //             }
    //             return (leftMax + rightMin) / 2.0; //如果是偶数的话返回结果
    //         }
    //     }
        
    //     return 0.0;
    // }

};
// @lc code=end

