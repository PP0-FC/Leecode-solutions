/**
 * @problem: 旋转字符串
 * @approach: 将字符串 s 旋转 k 位后得到的字符串为 s[k:] + s[:k]，其中 s[k:] 表示字符串 s 从第 k 个字符开始到末尾的子串，s[:k] 表示字符串 s 从开头到第 k 个字符之前的子串。我们可以枚举 k 的值，从 0 到 len(s)-1，判断旋转后的字符串是否等于 goal。
 * @time_complexity: O(n^2)，其中 n 是字符串 s 的长度。需要遍历字符串 s 来构建旋转的字符串。
 * @space_complexity: O(n)，其中 n 是字符串 s 的长度。需要创建一个新的字符串来存储旋转的字符串。
 */

bool rotateString(char* s, char* goal) 
{
    int len_s = strlen(s);
    int len_g = strlen(goal);

    if(len_s != len_g)  return false;

    for(int i = 0; i < len_s; i++)
    {
        char temp = s[0];
        for(int j = 0; j < len_s - 1; j++)
        {
            s[j] = s[j + 1];
        }
        s[len_s - 1] = temp;

        char* ans = strstr(s, goal);
        if(ans != NULL)
        {
            return true;
        }
    }

    return false;
}