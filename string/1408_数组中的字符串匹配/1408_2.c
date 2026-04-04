/**
 * @problem: 字符串中的字符串匹配
 * @approach: 遍历数组中的每个字符串，检查它是否是其他字符串的子串。用KMP算法替代strstr，避免重复添加子串。
 * @time_complexity: O(m * n * k)，其中 m 是数组中字符串的平均长度，n 是数组中字符串的个数，k 是目标字符串的长度。外层循环遍历每个字符串，内层循环遍历其他字符串，KMP算法的时间复杂度是O(k)。
 * @space_complexity: O(1)，不考虑返回数组的空间。
 * @note: 外层循环用来寻找字串，内层循环用来寻找母串。当找到母串时要马上break，避免重复添加字串。如果内外层反过来的话，子串会被重复添加多次。
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
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

char** stringMatching(char** words, int wordsSize, int* returnSize) 
{
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    for(int i = 0; i < wordsSize; i++)
    {
        int len1 = strlen(words[i]);
        int* next = (int*)malloc(sizeof(int) * len1);
        build_next(next, words[i], len1);

        bool is_found = false;

        for(int j = 0; j < wordsSize; j++)
        {
            if(i == j)  continue;

            int Index1 = 0;
            for(int Index2 = 0; Index2 < strlen(words[j]); Index2++)
            {
                while(Index1 > 0 && words[i][Index1] != words[j][Index2])
                {
                    Index1 = next[Index1 - 1];
                }
                if(words[i][Index1] == words[j][Index2])
                {
                    Index1++;
                }

                if(Index1 == len1)
                {
                    result[*returnSize] = words[i];
                    (*returnSize)++;
                    is_found = true;
                    break;
                }
            }

            if(is_found == true)    break;
        }

        free(next);
    }

    return result;
}