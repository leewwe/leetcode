/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (52.86%)
 * Likes:    1201
 * Dislikes: 1389
 * Total Accepted:    363.6K
 * Total Submissions: 687.7K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */
class Solution {
public:
// 方法一：谷底 - 谷峰 
    // int maxProfit(vector<int>& prices) {
    //     if(prices.empty()){
    //         return 0;
    //     }
    //     int max = 0;
    //     int valley = prices[0];
    //     int peak = prices[0];
    //     for(int i = 0; i < prices.size() - 1;){
    //         while(i < prices.size() - 1 && prices[i + 1] <= prices[i]){
    //             ++i;
    //         }
    //         valley = prices[i];
    //         while(i < prices.size() - 1 && prices[i + 1] >= prices[i]){
    //             ++i;
    //         }
    //         // 这里很关键，这么写会在找不到山顶的时候，将peak和valley等值，最后就不会产生错误的结果
    //         peak = prices[i];
    //         max += (peak - valley);
    //     }
    //     return max;
    // }
// 方法二：
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int max = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            int diff = prices[i + 1] - prices[i];
            if(diff > 0){
                max += diff;
            }
        }
        return max;
    }
};

