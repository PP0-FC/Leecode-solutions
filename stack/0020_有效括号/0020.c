/**
 * @problem: 有效的括号
 * @approach: 栈
 * @time_complexity: O(n)
 * @space_complexity: O(n)
*/

// 用于获取括号的配对字符，例如'('对应')'，'{'对应'}'，'['对应']'。
char pair(char ch)
{
    if(ch == '(')   return ')';
    if(ch == '{')   return '}';
    if(ch == '[')   return ']';
    return 0;
}

bool isValid(char* s) 
{
    int len = strlen(s);
    char* stk = (char*)malloc(sizeof(char) * len);
    int sp = -1;    // 栈顶指针，初始值为-1，表示栈为空。

    // 如果字符串的长度为奇数，则不可能是有效的括号字符串，直接返回false。
    if(len % 2 == 1)    return false;

    for(int i = 0; i < len; i++)
    {
        char ch = pair(s[i]);
        // 遇到左括号，执行入栈操作，将其对应的右括号压入栈中。
        if(ch)
        {
            sp++;
            stk[sp] = ch;
        }
        // 遇到右括号，执行出栈操作。
        else
        {
            // 如果栈顶元素与当前右括号不匹配，或者栈为空，则说明括号字符串无效。
            if(sp == -1 || stk[sp] != s[i])
            {
                free(stk);
                return false;
            }
            // 如果匹配成功，则将栈顶元素出栈，继续检查下一个字符。
            else    
                sp--;
        }
    }
    
    bool result = (sp == -1);

    free(stk);

    return result;
}