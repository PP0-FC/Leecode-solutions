/**
 * @problem: 判断链表是否有环
 * @approach: 快慢指针，如果链表有环，快慢指针一定会相遇；如果链表无环，快指针会先到达链表末尾。
 * @time_complexity: O(n)，其中n是链表中节点的总数。
 * @space_complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    if(head == NULL || head->next == NULL)  return false;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}