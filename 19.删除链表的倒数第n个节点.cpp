/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.08%)
 * Likes:    742
 * Dislikes: 0
 * Total Accepted:    141.1K
 * Total Submissions: 370.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
// 递归相当于是利用了递归栈，所以说这道题直接用个栈直接迭代也可以
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // 处理空的链表
//         if (!head || !n) {
//             return head;
//         }
//         // 可能的节点
//         auto ret = head;
//         // 当删除正数的第一个节点的时候，放回retNext
//         auto retNext = head->next;
//         int cnt = 0;    // 对链表长度计数
//         int nBuf = n;   // 存储倒数的数
//         removeNthFromEnd_aux(head, cnt, nBuf);
//         if (cnt == n) { // 当倒数的数和计数值一样时，也就是删除第一个元素的时候
//             delete ret;
//             ret = retNext;
//         }
//         return ret;
//     }
// private:
//     // 递归辅助函数
//     void removeNthFromEnd_aux(ListNode* node, int& cnt, int& n) {
//         if (!node) {
//             return;
//         }
//         removeNthFromEnd_aux(node->next, ++cnt, n);
//         // 删除节点必须要到前一个节点去删除
//         if (n-- == 0) {
//             auto nodeNext = node->next;
//             node->next = nodeNext->next;
//             delete nodeNext;
//         }
//     }
public:
// 迭代的写法
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if (!head || n == 0) {
    //         return nullptr;
    //     }
    //     vector<ListNode*> listStack;

    //     while (head) {
    //         listStack.push_back(head);
    //         head = head->next;
    //     }
    //     delete listStack[listStack.size() - n];
    //     if (listStack.size() == 1) {    // 删除了唯一的元素
    //         return nullptr;
    //     }
    //     else if(listStack.size() == n) {    // 删除了首元素
    //         return listStack[1];
    //     }
    //     else if (n == 1) {      // 删除了最后一个元素
    //         listStack[listStack.size() - 2]->next = nullptr;
    //     }
    //     else {  // 删除中间的元素
    //         int next = listStack.size() - n + 1;
    //         int pre = next - 2;
    //         listStack[pre]->next = listStack[next];
    //     }
    //     return listStack.front();
    // }
// 双指针法，这个是最好的，最省内存的，只需要一遍遍历的
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n == 0) {
            return nullptr;
        }
        auto start = new ListNode(INT_MIN);
        auto pr = start;
        pr->next = head;
        auto ne = pr;
        for (auto i = 0; i < n + 1; ++i) {
            ne = ne->next;
        }
        while (ne) {
            pr = pr->next;
            ne = ne->next;
        }
        auto delNode = pr->next;
        ListNode* ret = head;
        if (pr->next == head) { // 删除第一个元素
            ret = ret->next;
        }
        pr->next = pr->next->next;
        // 删除对应的节点，防止内存泄漏
        delete delNode;
        delete start;
        return ret;
    }
};
// @lc code=end

