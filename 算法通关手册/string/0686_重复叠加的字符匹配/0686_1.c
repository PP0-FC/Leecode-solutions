/**
 * @problem: 重复的字符串匹配
 * @approach: 如果需要k个a才能覆盖b，那么a重复k次后就会包含b。如果k个a不能覆盖b，那么a重复k+1次后就会包含b。如果k+1个a仍然不能覆盖b，那么无论重复多少次a都无法覆盖b。
 * @time_complexity: O(n)，其中 n 是字符串 a 的长度。需要遍历字符串 a 来构建重复的字符串。
 * @space_complexity: O(n)，其中 n 是字符串 a 的长度。需要创建一个新的字符串来存储重复的字符串。
 */

int repeatedStringMatch(char* a, char* b) 
{
    int len_a = strlen(a);
    int len_b = strlen(b);

    // 向上取整，计算需要重复多少次 a 才能覆盖 b
    int cnt = len_b / len_a;
    if(len_b % len_a != 0)  cnt++;

    char* cnt_a = (char*)malloc(sizeof(char) * (len_a * (cnt + 1) + 1));

    for(int i = 0; i < cnt; i++)
    {
        strcpy(cnt_a + i * len_a, a);   // 直接用偏移量来复制字符串，会比一直用strcat更快，因为strcat需要每次都遍历cnt_a来找到末尾，而strcpy直接复制到指定位置即可
    }

    char* ans = strstr(cnt_a, b);
    if(ans != NULL)
    {
        free(cnt_a);
        return cnt;
    }
    else
    {
        strcat(cnt_a, a);
        cnt++;
    }

    ans = strstr(cnt_a, b);
    if(ans != NULL)
    {
        free(cnt_a);
        return cnt;
    }
    else
    {
        free(cnt_a);
        return -1;
    }
}