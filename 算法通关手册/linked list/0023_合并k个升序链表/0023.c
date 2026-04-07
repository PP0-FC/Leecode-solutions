/**
 * @problem: 合并k个升序链表
 * @approach: 分治法，递归地将k个链表两两合并，直到只剩下一个链表。
 * @time_complexity: O(n log k)，其中n是所有链表中节点的总数，k是链表的数量。每次合并两个链表的时间复杂度是O(n)，而合并的次数是O(log k)。
 * @space_complexity: O(1)，除了递归调用栈的空间外，合并链表的过程中只使用了常数级别的额外空间。
 * @note: 需要注意递归的边界条件，以及合并链表时要正确处理链表的连接。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // 合并两个有序链表的函数
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL && l2 == NULL)    return NULL;

    struct ListNode sentinel;
    sentinel.next = NULL;
    struct ListNode* cur = &sentinel;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if(l1 != NULL)
    {
        cur->next = l1;
    }
    else
    {
        cur->next = l2;
    }

    return sentinel.next;
}

// 分治法递归地将k个链表两两合并
struct ListNode* divide(struct ListNode** lists, int left, int right)
{
    if(left == right)    return lists[left];

    int mid = left + (right - left) / 2;

    struct ListNode* L1 = divide(lists, left, mid);
    struct ListNode* L2 = divide(lists, mid + 1, right);

    return merge(L1, L2);
}

// 主函数，调用分治法进行合并
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) 
{
    if(!listsSize)  return NULL;

    return divide(lists, 0, listsSize - 1);
}