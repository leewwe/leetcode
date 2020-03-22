/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.91%)
 * Likes:    4057
 * Dislikes: 0
 * Total Accepted:    361.5K
 * Total Submissions: 979.4K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
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
//  Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };

class Solution {
public:
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* ret = new ListNode(0);
    //     ListNode* tmp = ret;
    //     int incr = 0;
    //     while(l1 != NULL || l2 != NULL){
    //         auto v1 = (l1 == NULL ? 0 : l1->val);
    //         auto v2 = (l2 == NULL ? 0 : l2->val);
    //         auto sum = v1 + v2 + incr;
    //         incr = sum / 10;
    //         sum = sum % 10;
    //         tmp->next = new ListNode(sum);
    //         tmp = tmp->next;
    //         l1 = (l1 == NULL ? NULL : l1->next);
    //         l2 = (l2 == NULL ? NULL : l2->next);
    //     }
    //     if(incr){
    //         tmp->next = new ListNode(incr);
    //     }
    //     return ret->next;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* tmp = ret;
        int incr = 0;
        while(1){
            auto v1 = (l1 == NULL ? 0 : l1->val);
            auto v2 = (l2 == NULL ? 0 : l2->val);
            auto sum = v1 + v2 + incr;
            incr = sum / 10;
            sum = sum % 10;
            tmp->val = sum;
            l1 = (l1 == NULL ? NULL : l1->next);
            l2 = (l2 == NULL ? NULL : l2->next);
            if(l1 == NULL && l2 == NULL){
                break;
            }
            else{
                tmp->next = new ListNode(0);
                tmp = tmp->next;
            }
        }
        if(incr){
            tmp->next = new ListNode(incr);
        }
        return ret;
    }
};
// @lc code=end

