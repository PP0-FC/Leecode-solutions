/**
 * @problem: 链表的中间节点，如果链表有两个中间节点，则返回第二个中间节点。
 * @approach: 快慢指针，快指针每次移动两步，慢指针每次移动一步，当快指针到达链表末尾时，慢指针正好在链表的中间节点。    
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
struct ListNode* middleNode(struct ListNode* head) 
{
    // 有两个中间节点时：同步出发则返回第二哥中间节点，错位出发则返回第一个中间节点。
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }    

    return slow;
}