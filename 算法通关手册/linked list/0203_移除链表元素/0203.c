/**
 * @problem: 移除链表元素
 * @approach: 链表
 * @time_complexity: O(n) --- IGNORE ---
 * @space_complexity: O(1) --- IGNORE ---
 * @note: 函数在后台定义好了，不需要自己再重新定义，不然会出现重定义。
 *        设置哨兵节点，简化边界条件的处理。后续遍历链表，遇到目标值时删除节点，否则继续遍历。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode* sentinel = (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinel->next = head;
    struct ListNode* pre = sentinel;
    struct ListNode* cur = pre->next;
    
    while(cur != NULL)
    {
        if(cur->val == val)
        {
            struct ListNode* temp = cur;
            pre->next = cur->next;
            cur = cur->next;

            free(temp);
        }
        else
        {
            pre = pre->next;
            cur = cur->next;
        }
    }
    return sentinel->next;
}