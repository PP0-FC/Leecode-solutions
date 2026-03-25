/**
 * @problem: 0169多数元素
 * @approach: 快速排序
 * @time_complexity: 平均：O(nlogn)。最坏：O(n*n)。
 * @space_complexity: O(1)
 * @note: 可以测试通过，但是判题会超时。
 */
void swap(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int patitation(int* nums , int left , int right)
{
    int i = left;
    int j = right;
    int pivot = nums[left];

    while(i < j)
    {
        while(i < j && nums[j] >= pivot)
        {
            j--;
        }
        while(i < j && nums[i] <= pivot)
        {
            i++;
        }
        swap(&nums[i] , &nums[j]);        
    }
    swap(&nums[left] , &nums[i]);

    return i;
}

void quiksort(int* nums , int left , int right)
{
    if(left < right)
    {
        int pi = patitation(nums , left , right);
        quiksort(nums , left , pi - 1);
        quiksort(nums , pi + 1 ,right);
    }
}

int majorityElement(int* nums, int numsSize) 
{
    int left = 0;
    int right = numsSize - 1;
    quiksort(nums , left , right);

    return nums[numsSize / 2];
}