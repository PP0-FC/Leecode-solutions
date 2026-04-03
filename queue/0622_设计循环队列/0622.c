/**
 * @problem: 设计循环队列
 * @approach: 使用一个数组来实现循环队列，维护front和rear指针来表示队列的头部和尾部位置。通过模运算实现循环效果。
 * @time_complexity: O(1) for each operation
 * @space_complexity: O(k) where k is the capacity of the queue
 */

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * (k+1));
    obj->front = 0;
    obj->rear = 0;
    obj->capacity = k + 1; 

    return obj;   
}

// 声明函数原型，避免编译器警告
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if(myCircularQueueIsFull(obj))
    {
        return false;
    }

    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj))
    {
        return false;
    }    

    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }    

    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }    

    int rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    return obj->data[rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    if(obj->front == obj->rear)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
    if((obj->rear + 1) % obj->capacity == obj->front)
        return true;
    else
        return false;    
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
    free(obj->data);
    free(obj);    
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/