/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (60.46%)
 * Likes:    905
 * Dislikes: 0
 * Total Accepted:    211.3K
 * Total Submissions: 349.1K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
class Solution {
public:
// 
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if(!l1 && l2){
    //         return l2;
    //     }
    //     else if(l1 && !l2){
    //         return l1;
    //     }
    //     auto ret = new ListNode(0);
    //     auto retBuf = ret;
    //     while (l2) {
    //         retBuf->next = new ListNode(l2->val);
    //         retBuf = retBuf->next;
    //         l2 = l2->next;
    //     }
    //     retBuf = ret->next;
    //     auto loc = ret;
    //     while (l1 || l2) {
    //         auto x1 = l1->val;
    //         auto flag = 1;
    //         while (retBuf) {
    //             auto x2 = retBuf->val;
    //             if (x1 == x2) {
    //                 loc = retBuf;
    //                 flag = 0;
    //                 //retBuf = retBuf->next;
    //                 break;
    //             }
    //             else if (x1 < x2) {
    //                 loc = retBuf;
    //                 flag = -1;
    //                 //retBuf = retBuf->next;
    //                 break;
    //             }
    //             flag = 1;
    //             loc = retBuf;
    //             retBuf = retBuf->next;
    //         }
    //         switch (flag) {
    //         case 0: {
    //             auto tmp = loc->next;
    //             loc->next = new ListNode(x1);
    //             loc->next->next = tmp;
    //             loc = loc->next;
    //         }
    //                 break;
    //         case -1: {
    //             auto tmp = loc->next;
    //             loc->next = new ListNode(x1);
    //             loc->next->next = tmp;
    //             int num = 0;
    //             num = loc->val;
    //             loc->val = loc->next->val;
    //             loc->next->val = num;
    //             loc = loc->next;
    //         }
    //                  break;
    //         default: {
    //             loc->next = new ListNode(x1);
    //             loc = loc->next;
    //         }
    //                  break;
    //         }
    //         l1 = l1->next;
    //     }
    //     return ret->next;
    // }
    
// 递归，会修改原始数据，这样做是否合理，我表示疑惑
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    //     if(!l1){
    //         return l2;
    //     }
    //     else if(!l2){
    //         return l1;
    //     }
    //     else if(l1->val < l2->val){
    //         l1->next = mergeTwoLists(l1->next, l2);
    //         return l1;
    //     }
    //     else{
    //         l2->next = mergeTwoLists(l1, l2->next);
    //         return l2;
    //     }
    // }
 
// 迭代，不会修改原始数据，迭代的方法只是返回一个重新的组织的链表头指针
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto ret = new ListNode(0);
        auto prev = ret;
        while (l1 || l2) {
            if (l1 && l2) {
                auto x1 = l1->val;
                auto x2 = l2->val;
                if (x1 < x2) {
                    prev->next = l1;
                    prev = prev->next;
                    l1 = l1->next;
                }
                else {
                    prev->next = l2;
                    prev = prev->next;
                    l2 = l2->next;
                }
            }
            else if (!l1) {
                prev->next = l2;
                prev = prev->next;
                l2 = l2->next;
            }
            else {
                prev->next = l1;
                prev = prev->next;
                l1 = l1->next;
            }
        }
        return ret->next;
    }
};
// @lc code=end

