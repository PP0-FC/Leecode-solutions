/**
 * @problem: 输入一个字符串，计算字符串中的表达式的值。
 * @approach: 栈
 * @time_complexity: O(n)
 * @space_complexity: O(n)
 */

int calculate(char* s) 
{
    int len = strlen(s);
    int* stk = (int*)malloc(sizeof(int) * len);
    int sp = -1;

    int num = 0;        // 当前正在处理的数字，初始值为0。
    char presign = '+'; // 当前数字前面的运算符，初始值为'+'，表示默认第一个数字是正数。

    for(int i = 0; i < len; i++)
    {
        // 如果当前字符是数字，则将其转换为整数，并累加到num中，支持多位数字的处理。
        if(isdigit(s[i]))
        {
            num = num * 10 + (int)(s[i] - '0');
        }

        // 如果当前字符不是数字且不是空格，或者已经处理到字符串的最后一个字符，则对num进行清算。
        if(!isdigit(s[i]) && s[i] != ' ' || i == len - 1)
        {
            // 根据presign的值，将num按照相应的运算符进行处理，并将结果压入栈中。
            switch(presign)
            {
                case '+':
                    stk[++sp] = num;
                    break;
                case '-':
                    stk[++sp] = -num;
                    break;
                case '*':
                    stk[sp] *= num;
                    break;
                case '/':
                    stk[sp] /= num;
                    break;
            }
            // 更新presign为当前字符，并重置num为0，准备处理下一个数字。
            presign = s[i];
            num = 0;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < sp+1; i++)
    {
        ans += stk[i];
    }

    free(stk);

    return ans;
}