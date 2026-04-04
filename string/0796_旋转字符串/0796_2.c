/**
 * @problem: 旋转字符串
 * @approach: "s + s" 中包含了 s 的所有旋转字符串，因此我们只需要判断 goal 是否是 "s + s" 的子串即可。
 * @time_complexity: O(n)，其中 n 是字符串 s 的长度。需要遍历字符串 s 来构建旋转的字符串。
 * @space_complexity: O(n)，其中 n 是字符串 s 的长度。需要创建一个新的字符串来存储旋转的字符串。
 */

 bool rotateString(char* s, char* goal) 
{
    int len_s = strlen(s);
    int len_g = strlen(goal);

    if(len_s != len_g)  return false;

    char* double_s = (char*)malloc(sizeof(char) * (2 * len_s + 1));

    strcpy(double_s, s);
    strcat(double_s, s);

    char* ans = strstr(double_s, goal);

    free(double_s);

    return ans != NULL;
}