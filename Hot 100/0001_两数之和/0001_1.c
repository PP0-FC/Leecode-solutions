/**
 * @problem: 两数之和,返回数组下标
 * @approach: 枚举法
 * @time_complexity: O(n^2)
 * @space_complexity: O(1)
 */ 

#include <stdlib.h> 

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    *returnSize = 2;
    int* ans = malloc(sizeof(int) * 2);
    
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return 0;
}