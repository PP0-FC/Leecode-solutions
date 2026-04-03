/**
 * @problem: 用队列实现栈
 * @approach: 使用一个循环队列来模拟栈的行为。每次入栈时，将新元素加入队尾，然后将之前的元素依次移动到新元素的后面，这样就保证了队头始终是栈顶元素。
 * @time_complexity: O(n) for push operation, O(1) for pop, top and empty operation
 * @space_complexity: O(n) where n is the number of elements in the stack
 */

typedef struct {
    int* data;
    int front;
    int rear;
    int capacity;

    int size;
} MyStack;


MyStack* myStackCreate() 
{
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->data = (int*)malloc(sizeof(int) * 105);
    obj->front = 0;
    obj->rear = 0;
    obj->capacity = 105;

    obj->size = 0;;

    return obj;
}

void myStackPush(MyStack* obj, int x) 
{
    obj->data[obj->rear] = x;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;

    // 将之前的元素依次移动到新元素的后面
    for(int i = 0; i < obj->size - 1; i++)
    {
        int temp = obj->data[obj->front];
        obj->data[obj->rear] = temp;
        obj->rear = (obj->rear + 1) % obj->capacity;
        obj->front = (obj->front + 1) % obj->capacity;
    }
}

int myStackPop(MyStack* obj) 
{
    int ans = obj->data[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return ans;
}

int myStackTop(MyStack* obj) 
{
    return obj->data[obj->front];
}

bool myStackEmpty(MyStack* obj) 
{
    return obj->size == 0;
}

void myStackFree(MyStack* obj) 
{
    free(obj->data);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/