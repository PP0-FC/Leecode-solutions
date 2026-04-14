/**
 * @problem: 回文链表
 * @approach: 新建一个数组,遍历链表元素，将val存入数组中，再用双指针判断数组是否是回文。
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
bool isPalindrome(struct ListNode* head) {
    int* arr = malloc(sizeof(int) * 300000);
    struct ListNode* Index = head;
    int i = 0;
    while(Index != NULL) {
        arr[i++] = Index->val;
        Index = Index->next;
    }
    int left = 0, right = i - 1;
    while(left <right) {
        if(arr[left] != arr[right]) {
            return false;
        }
        else {
            left++, right--;
        }
    }
    free(arr);
    return true;
}