/**
 * @problem: 合并两个有序链表
 * @approach: 设置哨兵节点
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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode sentinel;   // 在堆区开辟内存，建立一个实体哨兵节点。
    sentinel.next = NULL;
    struct ListNode* head = &sentinel;

    //  两个都不为NULL，才需要比较，如过一个链表为空，说明另一个链表的剩余部分都比当前节点大，并且是升序。
    while(list1 != NULL && list2 != NULL) {
        if(list1->val < list2->val) {
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        else {
            head->next = list2;
            list2 = list2->next;
            head = head->next;
        }
    }
    if(list1) {
        head->next = list1;
    }
    if(list2) {
        head->next = list2;
    }

    return sentinel.next;
}