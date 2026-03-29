/**
 * @problem: 库存管理
 * @approach: 堆排序
 * @time_complexity: O(nlogn)。
 * @space_complexity: O(1)
 * @note: 题目给的数组不是一个堆，只是普通二叉树。所以需要先构建一个大顶堆，然后再进行堆排序。构建大顶堆从最后一个非叶子节点开始，依次向前进行堆化。堆排序的过程是将堆顶元素与最后一个元素交换，然后对剩余的元素进行堆化，直到所有元素都被排序。
 */

// 交换函数
void swap(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* nums , int numsSize , int i)
{
    int large = i;
    int L_child = i*2 + 1;
    int R_child = i*2 + 2;

    if(L_child < numsSize && nums[L_child] > nums[large])
        large = L_child;
    if(R_child < numsSize && nums[R_child] > nums[large])
        large = R_child;

    if(large != i)
    {
        swap(&nums[large] , &nums[i]);
        heapify(nums , numsSize , large);
    }
}


int* inventoryManagement(int* stock, int stockSize, int cnt, int* returnSize) 
{
    // 构建大顶堆
    for(int i = stockSize / 2 - 1 ; i >= 0 ; i--)
    {
        heapify(stock , stockSize, i);
    }

    // 堆排序
    for(int j = stockSize - 1 ; j >= 0 ; j--)
    {
        swap(&stock[0] , &stock[j]);
        heapify(stock , j , 0);
    }
   
    int* answer = malloc(sizeof(int) * cnt);  // 注意：这里需要分配内存来存储结果数组
    for(int i = 0 ; i < cnt ; i++)
    {
        answer[i] = stock[i];
    }

    *returnSize = cnt;
    return answer;
}