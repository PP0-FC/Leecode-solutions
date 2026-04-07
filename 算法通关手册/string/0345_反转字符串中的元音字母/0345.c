/**
 * @problem: 反转字符串中的元音字母
 * @approach: 对撞双指针，使用两个指针分别指向字符串的开头和结尾，移动指针直到找到元音字母，然后交换两个指针所指的字符，继续移动指针，直到两个指针相遇
 * @time_complexity: O(n)，其中 n 是字符串的长度。
 * @space_complexity: O(1)，只使用了常数级别的额外空间。
 */

char vowel[] = "aeiouAEIOU";

int isVowel(char ch)
{
    for(int i = 0 ; vowel[i] != '\0' ; i++)
    {
        if(vowel[i] == ch)
            return 1;
    }
    return 0;
}

char* reverseVowels(char* s) 
{
    int left = 0;
    int right = strlen(s) - 1;
    while(left < right)
    {
        while(!isVowel(s[left]) && left < right)
        {
            left++;
        }
        while(!isVowel(s[right]) && left < right)
        {
            right--;
        }
        //注意这里用if语句而不是while语句，因为当两个指针所指的字符都是元音字母时，只需要交换一次即可，如果用while语句会导致指针停留在相同位置，进入死循环
        if(isVowel(s[left]) && isVowel(s[right]))
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    return s;
}