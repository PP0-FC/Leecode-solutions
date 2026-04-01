/**
 * @problem: 排序链表
 * @approach: 归并排序
 * @time_complexity: O(n^2)
 * @space_complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode* merge(struct ListNode* L1, struct ListNode* L2)
 {
    // 注意这里是创建一个结构体变量，而不是指针变量，所以不需要分配内存。这是用到“栈内存”，函数结束之后会自动释放，不需要手动释放内存。
    struct ListNode sentinel;
    sentinel.next = NULL;
    struct ListNode* cur = &sentinel;

    while(L1 != NULL && L2 != NULL)
    {
        if(L1->val > L2->val)
        {
            // 将L2节点连接到合并链表的尾部，并将L2指针移动到下一个节点
            cur->next = L2;
            L2 = L2->next;
        }
        else
        {
            // 将L1节点连接到合并链表的尾部，并将L1指针移动到下一个节点
            cur->next = L1;
            L1 = L1->next;
        }
        cur = cur->next;
    }

    if(L1 != NULL)
    {
        cur->next = L1;
    }
    else
    {
        cur->next = L2;
    }

    return sentinel.next;   // 要注意哨兵节点是结构体变量，不要写成sentinel->next了。
 }

struct ListNode* sortList(struct ListNode* head) 
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }

    // 使用快慢指针找到链表的中点。这里一定要注意错位！
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL;

    // 递归排序左右两部分链表
    struct ListNode* Left = sortList(head);
    struct ListNode* Right = sortList(mid);
    
    // 合并排序后的左右两部分链表
    return merge(Left, Right);
}