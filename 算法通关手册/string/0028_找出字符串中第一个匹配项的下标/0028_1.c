/**
 * @problem: 找出字符串中第一个匹配项的下标
 * @approach: Brute Force.
 * @time_complexity: O(m*n) where m is the length of haystack and n is the length of needle
 * @space_complexity: O(1) for the pointers and temporary variables
 */

int strStr(char* haystack, char* needle) 
{
    int len = strlen(needle);
    int Index1 = 0;
    int Index2 = 0;
    while(haystack[Index1] != '\0')
    {
        if(haystack[Index1] == needle[Index2])
        {
            Index1++;
            Index2++;
        }
        else
        {
            Index1 = Index1 - Index2 + 1;
            Index2 = 0;
        }

        if(Index2 == len)
        {
            return Index1 - len;
        }
    }    
    return -1;
}