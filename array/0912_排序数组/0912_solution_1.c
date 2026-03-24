/**
 * @problem: 将数组排序为升序
 * @approach: 希尔排序
 * @time_complexity: O(nlogn)
 * @space_complexity: O(1)
 */
int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize;
    int temp;
    int gap = numsSize/2;

    for(gap ; gap >0 ; gap /= 2)
    {
        for(int i = gap ; i < numsSize ; i++)
        {
            int j = i;
            temp = nums[i];

            while(j > gap-1 && nums[j-gap] > temp)
            {
                nums[j] = nums[j-gap];
                j -= gap;
            }
            nums[j] = temp;
        }
    }

    return nums;
}