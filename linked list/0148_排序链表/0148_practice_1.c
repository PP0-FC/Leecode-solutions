/**
 * @problem: 排序链表
 * @approach: 冒泡排序
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
    // 链表为空或者只有一个节点，无需排序
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }

    struct ListNode* tail = NULL;   // 已经排序好的部分的尾节点，初始为NULL。
    struct ListNode* cur = head;    // 当前节点，从头开始遍历链表

    // 外层循环控制排序的轮数，每轮将最大的元素冒泡到尾部，直到tail指向链表的头节点。
    while(tail != head)
    {
        // 内层循环进行冒泡排序，将当前节点与下一个节点进行比较，如果当前节点的值大于下一个节点的值，则交换它们的值。
        while(cur->next != tail)
        {
            struct ListNode* nextNode = cur->next;
            if(cur->val >= nextNode->val)
            {
                swap(&(cur->val) , &(nextNode->val));
                cur = cur->next;
                continue;
            }
            
            cur = cur->next;
        }
        // 每轮结束后，tail指向当前已经排序好的部分的尾节点，cur重新指向链表的头节点，进行下一轮排序。
        tail = cur;
        cur = head;
    }

    return head;
}