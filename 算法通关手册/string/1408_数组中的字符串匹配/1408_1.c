/**
 * @problem: 字符串中的字符串匹配
 * @approach: 遍历数组中的每个字符串，检查它是否是其他字符串的子串。
 * @time_complexity: O(m * n * k)，其中 m 是数组中字符串的平均长度，n 是数组中字符串的个数，k 是目标字符串的长度。
 * @space_complexity: O(1)，不考虑返回数组的空间。
 * @note: 外层循环用来寻找字串，内层循环用来寻找母串。当找到母串时要马上break，避免重复添加字串。如果内外层反过来的话，子串会被重复添加多次。
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) 
{
    int cnt = 0;
    char** result = (char**)malloc(sizeof(char*) * wordsSize);

    for(int i = 0; i < wordsSize; i++)
    {
        for(int j = 0; j < wordsSize; j++)
        {
            if(i == j)  continue;
            
            char* ans = strstr(words[j], words[i]);
            if(ans != NULL)
            {
                result[cnt] = words[i];
                cnt++;
                break;
            }
        }
    }

    *returnSize = cnt;
    return result;
}