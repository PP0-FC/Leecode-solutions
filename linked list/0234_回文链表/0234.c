/**
 * @problem: 回文链表
 * @approach: 先把链表的值存储到数组中，然后使用双指针判断是否是回文。
 * @time_complexity: O(n) 
 * @space_complexity: O(n)
 * @note: 要给arr分配足够的空间，测试用例很大，会溢出。还有就是要记得释放内存。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) 
{
    struct ListNode* Index = head;
    int* arr = (int*)malloc(sizeof(int) * 300000);
    int i = 0;
    while(Index != NULL)
    {
        arr[i++] = Index->val;
        Index = Index->next;
    }

    int left = 0;
    int right = i - 1;
    while(left < right)
    {
        if(arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }
    free(arr);
    return true;
}