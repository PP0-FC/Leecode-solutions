/**
 * @problem: 验证回文串
 * @approach: 使用双指针方法，分别从字符串的两端向中间移动，跳过非字母数字字符，并比较对应位置的字符是否相同（忽略大小写）。
 * @time_complexity: O(n) where n is the length of the string
 * @space_complexity: O(1) for the pointers and temporary variables
 * @note: 需要包含<ctype.h>头文件以使用isalnum和tolower函数,会用这两个就简单了。
 */

bool isPalindrome(char* s) 
{
    int left = 0;
    int right = strlen(s) - 1;

    while(left < right)
    {
        while(left < right && !isalnum(s[left]))
            left++;
        while(left < right && !isalnum(s[right]))
            right--;
        if(left < right)
        {
            if(tolower(s[left]) != tolower(s[right]))
                return false;
        }

        left++;
        right--;
    }

    return true;
}