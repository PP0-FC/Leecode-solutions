/**
 * @problem: 旋转字符串
 * @approach: 用KMP算法判断 goal 是否是 "s + s" 的子串。
 * @time_complexity: O(n)，其中 n 是字符串 s 的长度。需要遍历字符串 s 来构建旋转的字符串。
 * @space_complexity: O(n)，其中 n 是字符串 s 的长度。需要创建一个新的字符串来存储旋转的字符串。
 */

 // 构建next数组
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

bool rotateString(char* s, char* goal) 
{
    int len_s = strlen(s);
    int len_g = strlen(goal);

    if(len_s != len_g)  return false;

    int* next = (int*)malloc(sizeof(int) * len_g);
    build_next(next, goal, len_g);

    int j = 0;
    for(int i = 0; i < 2 * len_s; i++)
    {
        while(j > 0 && s[i % len_s] != goal[j])
        {
            j = next[j - 1];
        }
        if(s[i % len_s] == goal[j])
        {
            j++;
        }
        
        if(j == len_g)
        {
            free(next);
            return true;
        }
    }

    free(next);
    return false;
}