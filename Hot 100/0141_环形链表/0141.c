/**
 * @problem: 环形链表
 * @approach: 快慢指针，若快指针追上了慢指针，则该链表是环形链表
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
bool hasCycle(struct ListNode *head) {
    while(head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}