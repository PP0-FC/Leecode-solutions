/**
 * @problem: 删除链表的倒数第 N 个节点
 * @approach: 使用快慢指针，快指针比慢指针快 N 步，当快指针到终点时，慢指针刚好指向倒数第 N 个节点。
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: 力扣已经替我们定义了结构体，如注释所示，不需要再自己定义链表结构体。
 */ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode sentinel;
    sentinel.next = head;
    struct ListNode* slow = &sentinel;  // 慢指针从哨兵节点开始走，刚好可以到被删除节点的前一个节点，方便进行删除操作。
    struct ListNode* fast = head;
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* cur = slow->next;
    slow->next = cur->next;
    free(cur);
    return sentinel.next;
}