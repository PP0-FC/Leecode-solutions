/**
 * @problem: 环形链表,找出入环元素
 * @approach: 快慢指针
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
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* Index = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            while(Index != slow) {
            slow = slow->next;
            Index = Index->next;
            }
            return Index;
        }
    }
    return NULL;
} 