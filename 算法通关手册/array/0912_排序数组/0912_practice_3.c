/**
 * @problem: 将数组排序为升序
 * @approach: 插入排序
 * @time_complexity: O(n*n)
 * @space_complexity: O(1)
 * @note: 题目要求时间复杂度位O(nlogn)，插入排序不满足，仅作为练习
 */
int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    int n = numsSize;
    *returnSize = n;
    int temp;
    int j;
    int Index;
    for(int i = 0 ; i < n ; i++)
    {
        j = i - 1;
        temp = nums[i];
        while(j >= 0 && nums[j] > temp)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
    return nums;
}