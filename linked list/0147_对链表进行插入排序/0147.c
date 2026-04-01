/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) 
{
    struct ListNode* sentinel = (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinel->next = head;

    struct ListNode* tail = head;
    struct ListNode* cur = tail->next;

    while(cur != NULL)
    {
        struct ListNode* pre = sentinel;
        if(cur->val >= tail->val)
        {
            tail = tail->next;
            cur = cur->next;
            continue;
        }
        else
        {
            while(pre->next->val < cur->val)
            {
                pre = pre->next;
            }

            tail->next = cur->next; 
            cur->next = pre->next;  //要先链接待插入节点与后续节点。
            pre->next = cur;        //再链接待插入节点与前驱节点。

            cur = tail->next;
        }
    }

    struct ListNode* newhead = sentinel->next;
    free(sentinel);

    return newhead;
}