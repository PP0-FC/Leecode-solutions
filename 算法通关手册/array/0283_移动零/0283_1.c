/**
 * @problem: 移动所有零到末尾
 * @approach: 冒泡排序
 * @time_complexity: O(n*n)
 * @space_complexity: O(1)
 */
void moveZeroes(int* nums, int numsSize) 
{
    int n = numsSize;
    int temp;
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(nums[j] == 0)
            {
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}