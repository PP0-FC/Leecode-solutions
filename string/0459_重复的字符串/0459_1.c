/**
 * @problem: 重复的子字符串
 * @approach: 假设“s”符合要求，那么将“s+s”掐头去尾之后，中间必然会出现一个“s”。
 * @time_complexity: O(n)，其中 n 是字符串的长度。
 * @space_complexity: O(n)，其中 n 是字符串的长度。需要创建一个新的字符串来存储“s+s”。
 */

bool repeatedSubstringPattern(char* s) 
{
    int len = strlen(s);
    if(len == 0) return false;

    //创建一个新的字符串来存储“s+s”，要注意给’\0'留出空间
    char* double_s = (char*)malloc(sizeof(char) * (2 * len + 1));

    strcpy(double_s, s);
    strcat(double_s, s);

    //去尾，把最后一个字符改为'\0'
    double_s[2 * len - 1] = '\0';

    //掐头,从第二个字符开始查找s
    char* ans = strstr(&double_s[1], s);

    free(double_s);

    return ans != NULL;
}