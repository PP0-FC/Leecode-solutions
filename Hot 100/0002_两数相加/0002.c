/**
 * @problem: 两数相加，返回结果链表
 * @approach: 递归模拟
 * @time_complexity: O(n)
 * @space_complexity: O(n)
 * @note: 力扣已经替我们定义了结构体，如注释所示，不需要再自己定义链表结构体。
 */ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwo(struct ListNode* l1, struct ListNode* l2, int carry) {
    // 递归结束条件
    if(l1 == NULL && l2 == NULL && carry == 0) {
        return NULL;
    }

    int sum = carry;
    if(l1) {
        sum += l1->val;
        l1 = l1->next;
    }
    if(l2) {
        sum += l2->val;
        l2 = l2->next;
    }
    // 将结果记录进当前节点
    struct ListNode* cur = malloc(sizeof(struct ListNode));
    cur->val = sum % 10;
    cur->next = addTwo(l1, l2, sum / 10);   //递归计算下一个节点的值

    return cur;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwo(l1, l2, 0);
}