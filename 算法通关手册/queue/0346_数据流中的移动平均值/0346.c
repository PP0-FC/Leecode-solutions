/**
 * @problem: 数据流中的移动平均值
 * @approach: 循环队列
 * @time_complexity: O(1) for each operation
 * @space_complexity: O(size) where size is the window size
 */

typedef struct {
    double *data;
    int front;
    int rear;
    int capacity;

    double win_sum; // 当前窗口内元素的和
    int cnt;        // 当前窗口内元素的数量
} MovingAverage;


MovingAverage* movingAverageCreate(int size) 
{
    MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
    obj->data = (double*)malloc(sizeof(double) * (size + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->capacity = size + 1;

    obj->win_sum = 0;
    obj->cnt = 0;

    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) 
{
    // 如果队列已满，先移除队头元素的值
    if((obj->rear + 1) % obj->capacity == obj->front)
    {
        obj->win_sum -= obj->data[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;
        obj->cnt--;
    }

    // 将新元素加入队尾，并更新窗口和计数
    obj->data[obj->rear] = (double)val;
    obj->win_sum += obj->data[obj->rear];
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->cnt++;

    // 返回当前窗口的平均值
    return obj->win_sum / obj->cnt;
}

void movingAverageFree(MovingAverage* obj) 
{
    free(obj->data);
    free(obj);    
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/