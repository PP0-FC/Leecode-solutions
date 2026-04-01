/**
 * @problem: 判断链表是否有环，如果有环，返回环的入口节点；如果没有环，返回NULL。
 * @approach: 快慢指针，如果链表有环，快慢指针一定会相遇；如果链表无环，快指针会先到达链表末尾。详细算法见参考书题解。
 * @time_complexity: O(n)，其中n是链表中节点的总数。
 * @space_complexity: O(1)
 * @note: 当快慢指针相遇时，快指针已经走了两倍的路程，所以快指针比慢指针多走了一个环的长度。此时我们让一个指针从链表头部出发，另一个指针从相遇点出发，每次都移动一步，当它们再次相遇时，相遇点就是环的入口节点。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    if(head == NULL || head->next == NULL)  return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            struct ListNode* ans = head;
            while(ans != slow)
            {
                ans = ans->next;
                slow = slow->next;
            }
            return ans;
        }
    }
    return NULL;    
}