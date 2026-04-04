/**
 * @problem: 只出现一次的数字
 * @approach: 使用位操作异或运算。首先将所有数字进行异或运算，得到的结果是两个只出现一次的数字的异或结果。然后找到这个结果中任意一个为1的位，使用这个位将原数组分成两组，每组包含一个只出现一次的数字和一些成对出现的数字。最后对每组分别进行异或运算，得到的结果就是两个只出现一次的数字。
 * @time_complexity: O(n) since we need to iterate through all the numbers in the array twice
 * @space_complexity: O(1) since we are using a constant amount of space for the result and temporary variables
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = 2;
    int sum = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        sum ^= nums[i];
    }

    int* ans = (int*)malloc(sizeof(int) * 2);
    int bit = (uint)sum & -(uint)(sum);
    ans[0] = 0;     // 位运算要记得初始化结果，否则可能会得到错误的结果，因为在进行异或运算时，如果结果没有被初始化为0，那么它可能会包含一些垃圾值，导致最终的结果不正确
    ans[1] = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] & bit)
        {
            ans[0] ^= nums[i];
        }
        else
        {
            ans[1] ^= nums[i];
        }
    }

    return ans;
}