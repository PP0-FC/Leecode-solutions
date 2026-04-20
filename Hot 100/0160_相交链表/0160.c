/**
 * @problem: 相交链表
 * @approach: 双指针
 * @time_complexity: O(m + n)
 * @space_complexity: O(1)
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* Index1 = headA;
    struct ListNode* Index2 = headB;
    
    while(Index1 != Index2) {
        if(Index1 == NULL) {
            Index1 = headB;
        }
        else {
            Index1 = Index1->next;
        }
        if(Index2 == NULL) {
            Index2 = headA;
        }
        else {
            Index2 = Index2->next;
        }
    }
    return Index1;
}