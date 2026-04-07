/**
 * @problem: 奇偶链表
 * @approach: 链表
 * @time_complexity: O(n) --- IGNORE ---
 * @space_complexity: O(1) --- IGNORE ---
 * @note: 函数在后台定义好了，不需要自己再重新定义，不然会出现重定义。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) 
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }

    struct ListNode* odd = head;    // 奇数节点
    struct ListNode* evenhead = head->next;     // 偶数节点的头节点，后续需要连接到奇数节点的尾部
    struct ListNode* even = evenhead;   // 偶数节点 

    while(even != NULL && even->next != NULL)
    {
        // 奇数节点连接到下一个奇数节点
        odd->next = even->next;
        odd = odd->next;

        // 偶数节点连接到下一个偶数节点
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenhead;   // 将奇数节点的尾部连接到偶数节点的头部
    return head;
}