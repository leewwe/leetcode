/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
// 暴力法就不写了，非常简单，时间：O(mn)，空间O(1)

// 哈希表法 
    // ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    //     unordered_set<ListNode*> a_set;
    //     while (headA) {
    //         a_set.emplace(headA);
    //         headA = headA->next;
    //     }

    //     while (headB) {
    //         if (!a_set.emplace(headB).second) {
    //             return headB;
    //         }
    //         headB = headB->next;
    //     }
    //     return NULL;
    // }
// 双指针法，本质上是消除两个链表之间的长度不一样，补齐两者的长度，走一样的路线，a + all + b = b + all + a
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto pA = headA;
        auto pB = headB;
        while (pA || pB) {
            if(pA == pB && pA != NULL){
                return pA;
            }
            pA = pA == NULL ? pA = headB : pA = pA->next;
            pB = pB == NULL ? pB = headA : pB = pB->next;
        }
        return NULL;
    }


// 这个解法也是正确的
/* Here's my solution which is like approach 3 but a little different. I store the size of ListA and
ListB as len1 and len2. Then I reset the pointers to headA and headB and find the difference between
len1 and len2, and then let the pointer of the longer list proceed by the difference between len1
and len2. Finally, traverse through the lists again, the intersection node can be easily found. */
// 总结来说就一句话，必然在长一点的链表一定实在前面比短一点的长，因为，加入两者相交，那么在包括交点之后的链表长度是相等的
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode *p1 = headA;
    //     ListNode *p2 = headB;
    //     ListNode *ret = NULL;
    //     int len1 = 0;
    //     int len2 = 0;
    //     while(p1 != NULL) {
    //         len1++;
    //         p1 = p1->next;
    //     }
    //     while(p2 != NULL) {
    //         len2++;
    //         p2 = p2->next;
    //     }
    //     p1 = headA;
    //     p2 = headB;
    //     if(len1 > len2) {
    //         int diff = len1 - len2;
    //         for(int i = 0;i < diff;i++) {
    //             p1 = p1->next;
    //         }
    //     }else {
    //         int diff = len2 - len1;
    //         for(int i = 0;i < diff;i++) {
    //             p2 = p2->next;
    //         }
    //     }
    //     while(p1 != p2) {
    //         p1 = p1->next;
    //         p2 = p2->next;
    //     }
    //     return p1;
    // }
};
// @lc code=end

