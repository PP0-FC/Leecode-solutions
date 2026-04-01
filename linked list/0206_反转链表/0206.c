/**
 * @problem: 反转链表
 * @approach: 链表
 * @time_complexity: O(n) --- IGNORE ---
 * @space_complexity: O(1) --- IGNORE ---
 * @note: 函数在后台定义好了，不需要自己再重新定义，不然会出现重定义。
 */

/**
* Definition for singly-linked list.
struct ListNode 
{
    int val;
    struct ListNode *next;
}
*/
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    
    while(cur != NULL)
    {
        struct ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}