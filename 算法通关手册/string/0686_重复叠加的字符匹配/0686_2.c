/**
 * @problem: 重复的字符串匹配
 * @approach: 用KMP替代strstr。并且用循环的方式构建“a”拼凑的主串
 * @time_complexity: O(n)，其中 n 是字符串 a 的长度。需要遍历字符串 a 来构建重复的字符串。
 * @space_complexity: O(n)，其中 n 是字符串 b 的长度。需要创建一个next数组来存储每个位置的最长前缀长度。
 */

void build_next(int* next, char* s, int len)
{
    next[0] = 0;
    int j = 0;
    for(int i = 1; i < len; i++)
    {
        while(j > 0 && s[i] != s[j])
        {
            j = next[j - 1];
        }
        if(s[i] == s[j])
        {
            j++;
        }
        next[i] = j;
    }
}

int repeatedStringMatch(char* a, char* b) 
{
    int len_a = strlen(a);
    int len_b = strlen(b);

    if(len_a == 0)  return -1;

    int* next = (int*)malloc(sizeof(int) * len_b);
    build_next(next, b, len_b);

    int j = 0;
    for(int i = 0; i < len_a + len_b; i++)
    {
        while(j > 0 && a[i % len_a] != b[j])    // 这里的i % len_a就是在构建“a”拼凑的主串，i从0到len_a+len_b-1，保证了主串的长度至少为len_b，这样就能判断b是否是主串的子串了
        {
            j = next[j - 1];
        }
        if(a[i % len_a] == b[j])
        {
            j++;
        }
        if(j == len_b)
        {
            free(next);
            return ((i + 1 + len_a - 1) / len_a);
        }
    }
    free(next);
    return -1;
}