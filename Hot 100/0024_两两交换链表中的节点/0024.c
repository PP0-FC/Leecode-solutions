/**
 * @problem: 两两交换链表中的节点
 * @approach: 设置一个前置节点，用来跟踪每一组要交换的节点
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode sentinel;
    sentinel.next = head;
    struct ListNode* pre = &sentinel;
    while(pre->next != NULL && pre->next->next != NULL) {
        struct ListNode* node1 = pre->next;
        struct ListNode* node2 = pre->next->next;
        pre->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        pre = pre->next->next;
    }
    return sentinel.next;
}