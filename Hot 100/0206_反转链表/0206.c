/**
 * @problem: 反转链表
 * @approach: 新建一个尾节点，然后遍历链表元素，建立与新节点的链接
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: 力扣已经替我们定义了结构体，如注释所示，不需要再自己定义链表结构体。
 */ 

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* new = NULL;
    while(cur != NULL) {
        struct ListNode* temp = cur->next;
        cur->next = new;
        new = cur;
        cur = temp;
    }
    return new;
}