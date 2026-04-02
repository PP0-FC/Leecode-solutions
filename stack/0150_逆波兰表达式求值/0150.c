/**
 * @problem: 根据 逆波兰表示法，求表达式的值。
 * @approach: 栈
 * @time_complexity: O(n)
 * @space_complexity: O(n)
 */

bool sign(char* ch)
{
    switch(*ch)
    {
        case '+': return true;
        case '-': return true;
        case '*': return true;
        case '/': return true;
        default: return false;
    }
}

int evalRPN(char** tokens, int tokensSize) 
{
    int* stk = (int*)malloc(sizeof(int) * tokensSize);
    int sp = -1;

    for(int i = 0; i < tokensSize; i++)
    {
        char* token = tokens[i];
        // 如果当前token是一个运算符，则从栈顶弹出两个操作数，根据运算符进行计算，并将结果压入栈中。
        if(strlen(token) == 1 && sign(token))
        {
            int num2 = stk[sp--];
            int num1 = stk[sp--];

            switch(*token)
            {
                case '+': 
                    stk[++sp] = num1 + num2;
                    break;  
                case '-': 
                    stk[++sp] = num1 - num2;
                    break;
                case '*': 
                    stk[++sp] = num1 * num2;
                    break;
                case '/': 
                    stk[++sp] = num1 / num2;
                    break;
            }
        }
        // 如果当前token是一个数字，则将其转换为整数并压入栈中。
        else
        {
            stk[++sp] = atoi(token);
        }
    }
    int ans = stk[sp];

    free(stk);

    return ans;
}