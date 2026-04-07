/**
 * @problem: 给定一个经过编码的字符串，返回它解码后的字符串。编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * @approach: 使用两个栈来分别存储数字和字符串。
 * @time_complexity: O(n)
 * @space_complexity: O(n)
 */

char* decodeString(char* s) 
{
    int num_stk[1000];      // 用于存储数字的栈，num_stk[i]表示第i层嵌套的重复次数。
    char* str_stk[1000];    // 用于存储字符串的栈，str_stk[i]表示第i层嵌套的字符串。
    int sp = -1;

    // res用于构建当前层的字符串，num用于构建当前层的数字。
    char* res = (char*)calloc(10000, sizeof(char)); //calloc会将分配的内存初始化为0，这样res字符串初始为空字符串。
    int num = 0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        // 如果当前字符是数字，则将其转换为整数，并累加到num中，支持多位数字的处理。
        if(isdigit(s[i]))
        {
            num = num * 10 + (int)(s[i] - '0');
        }
        // 如果当前字符是字母，则将其追加到res字符串的末尾，构建当前层的字符串。
        else if(isalpha(s[i]))
        {
            int len = strlen(res);  // 获取当前res字符串的长度。
            res[len] = s[i];
            res[len+1] = '\0';
        }
        // 如果当前字符是左括号'['，则将当前构建的数字num和字符串res分别压入num_stk和str_stk栈中，并重置num和res，准备处理下一层嵌套。
        else if(s[i] == '[')
        {
            sp++;
            num_stk[sp] = num;

            // 将当前res字符串的内容复制到str_stk[sp]中，注意要为str_stk[sp]分配足够的内存来存储res字符串。
            str_stk[sp] = (char*)malloc(strlen(res) + 1);
            strcpy(str_stk[sp], res);

            // 重置num和res，准备处理下一层嵌套。
            num = 0;
            res[0] = '\0';
        }
        else if(s[i] == ']')
        {
            int k = num_stk[sp];
            char* pre = str_stk[sp];
            sp--;

            // 构建临时字符串，用来存储pre字符串和res字符串重复k次后的结果。
            char* temp = (char*)calloc(10000, sizeof(char));
            strcpy(temp, pre);

            for(int j = 0; j < k; j++)
            {
                strcat(temp, res);
            }

            strcpy(res, temp);

            free(temp);
            free(pre);
        }
    }

    return res;
}