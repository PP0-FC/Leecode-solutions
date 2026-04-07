/**
 * @problem: 反转字符串
 * @approach: 分离双指针，使用两个指针分别指向字符串的开头和结尾，交换两个指针所指的字符，然后向中间移动指针，直到两个指针相遇
 * @time_complexity: O(n)，其中 n 是字符串的长度。
 * @space_complexity: O(1)，只使用了常数级别的额外空间。
 */

void reverseString(char* s, int sSize) 
{
    int left = 0;
    int right = sSize - 1;
    while(left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}