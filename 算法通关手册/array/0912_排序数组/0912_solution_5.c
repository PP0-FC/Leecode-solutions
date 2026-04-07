/**
 * @problem: 将数组排序为升序
 * @approach: 计数排序
 * @time_complexity: O(n + k)，其中 n 是输入数组的大小，k 是输入数组中元素的范围。
 * @space_complexity: O(k)，其中 k 是输入数组中元素的范围。
 * @note: 要考虑到输入数组中的元素可能是负数，所以需要找到数组中的最大值和最小值来确定计数数组的大小。计数排序的基本思想是统计每个元素出现的次数，然后根据这些统计信息来构建排序后的数组。首先，创建一个计数数组来存储每个元素出现的次数，然后遍历输入数组，更新计数数组。最后，根据计数数组中的信息，将元素放回原始数组中，完成排序。
 */
int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    if (nums == NULL || numsSize <= 1) 
    {
        *returnSize = numsSize;
        return nums;
    }

    int MAX = nums[0];
    int MIN = nums[0];
    for(int i = 0 ; i < numsSize ; i++)
    {
        if(MAX < nums[i])
            MAX = nums[i];
        if(MIN > nums[i])
            MIN = nums[i];
    }

    int len = MAX - MIN;   
    int* count = malloc(sizeof(int) * (len + 1));
    if(count == NULL) return NULL;
    memset(count , 0 , sizeof(int) * (len + 1));

    for(int i = 0 ; i < numsSize ; i++)
    {
        count[nums[i]-MIN]++;
    }

    int Index = 0;
    for(int i = 0 ; i < len+1 ; i++)
    {
        while(count[i] != 0)
        {
            nums[Index++] = i + MIN;
            count[i]--;
        }
    }

    free(count);

    *returnSize = numsSize;
    return nums;
}