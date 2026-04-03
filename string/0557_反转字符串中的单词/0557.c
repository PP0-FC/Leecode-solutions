/**
 * @problem: 反转字符串中的单词
 * @approach: 使用双指针方法，首先使用一个指针遍历字符串，当遇到空格或字符串结尾时，使用另一个指针将当前单词进行反转。重复这个过程直到字符串末尾。
 * @time_complexity: O(n)，其中 n 是字符串的长度。
 * @space_complexity: O(1)，只使用了常数级别的额外空间。
 */

char* reverseWords(char* s) 
{
    int slow = 0;
    int fast = 0;
    while(s[fast] != '\0' && s[slow] != '\0')
    {
        fast++;
        if(s[fast] == ' ' || s[fast] == '\0')
        {
            int left = slow;
            int right = fast - 1;
            while(left < right)
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }

            if(s[fast] == '\0')
                break;

            slow = fast + 1;
        }
    }

    return s;
}