/**
 * @problem: 验证栈序列
 * @approach: 模拟法，使用一个栈来模拟入栈和出栈的过程。
 * @time_complexity: O(n)
 * @space_complexity: O(n)
 */

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) 
{
    int* stk = (int*)malloc(sizeof(int) * 3000);
    int sp = -1;
    int popIndex = 0;
    
    for(int i = 0; i < pushedSize; i++)
    {
        stk[++sp] = pushed[i];
        while(sp != -1 && stk[sp] == popped[popIndex])
        {
            sp--;
            popIndex++;
        }
    }

    bool ans = (sp == -1);

    free(stk);

    return ans;
}