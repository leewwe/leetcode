/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (37.91%)
 * Likes:    1880
 * Dislikes: 267
 * Total Accepted:    478.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, determine if it has a cycle in it.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * Can you solve it using O(1) (i.e. constant) memory?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// 使用一个hash set，时间复杂度为O(n),空间复杂度为O(n)
    // bool hasCycle(ListNode* head) {
    //     unordered_set<int*> us;
    //     auto head_buf = head;
    //     while (head_buf != NULL) {
    //         // 注意这里村的是内存地址
    //         auto res = us.emplace(&(head_buf->val));
    //         if (!res.second) {
    //             return true;
    //         }
    //         head_buf = head_buf->next;
    //     }
    //     return false;
    // }
// 快慢指针法
    bool hasCycle(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (slow && fast) {
            if (fast->next) {
                fast = fast->next->next;
            }
            else{
                return false;
            }
            if (fast == slow) {
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
// @lc code=end

