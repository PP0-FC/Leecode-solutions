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

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode sentinel;
    sentinel.next = NULL;
    struct ListNode* head = &sentinel;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            head->next = l1;
            head = head->next;
            l1 = l1->next;
        }
        else {
            head->next = l2;
            head = head->next;
            l2 = l2->next;
        }
    }
    if(l1) {
        head->next = l1;
    }
    if(l2) {
        head->next = l2;
    }
    return sentinel.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL;
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    return merge(left, right);
}