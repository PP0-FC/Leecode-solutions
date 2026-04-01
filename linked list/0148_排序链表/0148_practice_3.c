/**
 * @problem: 排序链表
 * @approach: 插入排序
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

struct ListNode* sortList(struct ListNode* head) 
{
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }

    // 创建一个哨兵节点，方便插入操作
    struct ListNode* sentinal = (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinal->next = head;

    // tail指向已经排序好的部分的尾节点，cur指向当前待插入的节点
    struct ListNode* tail = head;
    struct ListNode* cur = tail->next;

    // 遍历链表，将每个节点插入到已排序部分的正确位置
    while(cur != NULL)
    {
        // pre寻找待插入位置的前驱节点，初始为哨兵节点
        struct ListNode* pre = sentinal;
        // 如果当前节点的值大于等于tail节点的值，说明当前节点已经在正确位置，无需插入，直接移动tail和cur指针
        if(cur->val >= tail->val)
        {
            cur = cur->next;
            tail = tail->next;
            continue;
        }
        else
        {
            // 寻找待插入位置的前驱节点pre，使得pre->next节点的值大于cur节点的值
            while(cur->val > pre->next->val)
            {
                pre = pre->next;
            }

            tail->next = cur->next; // 将待插入节点从链表中移除
            cur->next = pre->next;  // 将待插入节点插入到正确位置
            pre->next =cur;         // 更新pre的next指针指向待插入节点

            cur = tail->next;       // 更新cur指向下一个待插入节点
        }
    }

    // 返回排序后的链表头节点，并释放哨兵节点的内存
    struct ListNode* newhead = sentinal->next;
    free(sentinal);

    return newhead;
}