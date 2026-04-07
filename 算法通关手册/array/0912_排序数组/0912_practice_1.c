/**
 * @problem: 将数组排序为升序
 * @approach: 冒泡排序
 * @time_complexity: O(n*n)
 * @space_complexity: O(1)
 * @note: 题目要求时间复杂度位O(nlogn)，冒泡排序不满足，仅作为练习
 */
int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    int temp;
    int n = numsSize;
    *returnSize = n;
    for(int i = 0 ; i < (n-1) ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(nums[j] > nums[j+1])
            {
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}