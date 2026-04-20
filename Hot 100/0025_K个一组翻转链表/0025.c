/**
 * @problem: K个一组翻转链表
 * @approach: 一个探路指针，每次忘后走k步，然后把走过的链表单独拎出来用翻转链表的函数
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

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while(cur != NULL) {
        struct ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode sentinel;
    sentinel.next = head;
    struct ListNode* pre = &sentinel;
    struct ListNode* end = &sentinel;

    while(pre != NULL) {
        for(int i = 0; i < k && end != NULL; i++) {
            end = end->next;
        }
        if(end == NULL) {
            break;
        }
        struct ListNode* start = pre->next;
        struct ListNode* next = end->next;
        end->next = NULL;
        pre->next = reverse(start);
        start->next = next;
        pre = start;
        end = start;
    }
    return sentinel.next;
}