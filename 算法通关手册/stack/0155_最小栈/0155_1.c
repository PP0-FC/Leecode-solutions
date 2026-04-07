/**
 * @problem: 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * @approach: 设置一个辅助栈，在每次push时存入当下的最小值，这样在pop时辅助栈也会同步弹出，保证辅助栈的栈顶永远是当前数据栈的最小值。
 * @time_complexity: O(1) for each operation
 * @space_complexity: O(n) in the worst case when all elements are the same and are the minimum.
 */

#define MAX_SIZE 30000

typedef struct {
    int* data_stk;
    int* min_stk;
    int sp;
} MinStack;


MinStack* minStackCreate() 
{
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->data_stk = (int*)malloc(sizeof(int) * MAX_SIZE);
    obj->min_stk = (int*)malloc(sizeof(int) * MAX_SIZE);
    obj->sp = -1;

    return obj;
}

void minStackPush(MinStack* obj, int val) 
{
    // 如果栈为空，直接将val压入数据栈和辅助栈。
    if(obj->sp == -1)
    {
        obj->sp++;
        obj->data_stk[obj->sp] = val;
        obj->min_stk[obj->sp] = val;
    }
    // 如果栈不为空，比较val与当前最小值，将较小的值压入辅助栈，同时将val压入数据栈。
    else
    {
        int cur_min = obj->min_stk[obj->sp];
        obj->sp++;
        if(val < cur_min)
        {
            obj->data_stk[obj->sp] = val;
            obj->min_stk[obj->sp] = val;
        }
        else
        {
            obj->data_stk[obj->sp] = val;
            obj->min_stk[obj->sp] = cur_min;
        }
    }
}

void minStackPop(MinStack* obj) 
{
    obj->sp--;    
}

int minStackTop(MinStack* obj) 
{
    return obj->data_stk[obj->sp];    
}

int minStackGetMin(MinStack* obj) 
{
    return obj->min_stk[obj->sp];
}

void minStackFree(MinStack* obj) 
{
    free(obj->data_stk);
    free(obj->min_stk);
    free(obj);    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/