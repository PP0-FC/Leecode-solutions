/**
 * @problem: 将数组排序为升序
 * @approach: 快速排序
 * @time_complexity: 平均：O(nlogn)。最坏：O(n*n)。
 * @space_complexity: O(1)
 */
void swap(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitation(int *nums , int left , int right)
{
    int i = left;
    int j = right;
    int pivot = nums[i];

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
        int pi = partitation(nums , left ,right);
        quiksort(nums , left , pi - 1);
        quiksort(nums , pi + 1 , right);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    int left = 0;
    int right = numsSize - 1;

    quiksort(nums , left ,right);

    *returnSize = numsSize;
    return nums;
}