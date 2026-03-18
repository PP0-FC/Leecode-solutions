/**
 * @problem: 将数组排序为升序
 * @approach: 选择排序
 * @time_complexity: O(n*n)
 * @space_complexity: O(1)
 * @note: 题目要求时间复杂度位O(nlogn)，冒泡排序不满足，仅作为练习
 */
int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    int n = numsSize;
    *returnSize = n;
    int temp;
    int minIndex;
    for(int i = 0 ; i < n-1 ; i++)
    {
        minIndex = i;
        for(int j = i ; j < n ; j++)
        {
            if(nums[minIndex] > nums[j])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }

    }
    return nums;
}