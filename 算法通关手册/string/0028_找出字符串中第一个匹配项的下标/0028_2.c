/**
 * @problem: 找出字符串中第一个匹配项的下标
 * @approach: KMP算法
 * @time_complexity: O(m + n) where m is the length of haystack and n is the length of needle
 * @space_complexity: O(n) for the next array
 */

 // 构建next数组，next[i]表示needle[0:i]的最长相等前后缀的长度
void build_next(int* next, char* s, int len)
{
    next[0] = 0;    // next[0]表示长度为1的字符串的最长相等前后缀的长度为0
    int j = 0;

    // 从第二个字符开始构建next数组
    for(int i = 1; i < len; i++)
    {
        // 当s[i]和s[j]不相等时，j回退到next[j-1]的位置继续比较，直到找到相等的字符或者j回退到0
        while(j > 0 && s[i] != s[j])
        {
            j = next[j - 1];
        }

        // 当s[i]和s[j]相等时，j向前移动一位，表示最长相等前后缀的长度增加1
        if(s[i] == s[j])
        {
            j++;
        }

        // 将当前的最长相等前后缀的长度记录在next数组中
        next[i] = j;
    }
}

int strStr(char* haystack, char* needle) 
{
    int len_h = strlen(haystack);
    int len_n = strlen(needle);

    if(len_h == 0 || len_h < len_n)   return -1;
    if(len_n == 0)  return 0;

    // 构建next数组
    int* next = (int*)malloc(sizeof(int) * len_n);
    build_next(next, needle, len_n);

    int j = 0;
    for(int i = 0; i < len_h; i++)
    {
        // 当haystack[i]和needle[j]不相等时，j回退到next[j-1]的位置继续比较，直到找到相等的字符或者j回退到0
        while(j > 0 && haystack[i] != needle[j])
        {
            j = next[j - 1];
        }

        // 当haystack[i]和needle[j]相等时，j向前移动一位，表示已经匹配了j+1个字符
        if(haystack[i] == needle[j])
        {
            j++;
        }

        // 当j等于needle的长度时，表示已经找到了一个完整的匹配项，返回匹配项的起始下标
        if(j == len_n)
        {
            free(next);
            return i - len_n + 1;
        }
    }

    free(next);
    return -1;
}