/**
 * @problem: 排序链表
 * @approach: 选择排序
 * @time_complexity: O(n^2)
 * @space_complexity: O(1)
 * @note: 能通过测试，但是提交会超时，仅做练习用。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct ListNode* sortList(struct ListNode* head) 
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }

    struct ListNode* cur = head;
    struct ListNode* min_Node = cur;

    while(cur->next != NULL)
    {
        struct ListNode* temp = cur;
        while(temp != NULL)
        {
            if(temp->val < min_Node->val)
            {
                swap(&(temp->val), &(min_Node->val));
            }
            temp = temp->next;
        }
        if(cur->val != min_Node->val)
        {
            swap(&(cur->val), &(min_Node->val));
        }
        cur = cur->next;
        min_Node = cur;
    }

    return head;
}