/**
 * @problem: 只出现一次的数字
 * @approach: 使用位操作逐位统计每个二进制位上1的个数。对于每个二进制位，如果1的个数不是3的倍数，那么说明只出现一次的数字在该位上是1，否则是0。
 * @time_complexity: O(n) since we need to iterate through all the numbers in the array once for each of the 32 bits
 * @space_complexity: O(1) since we are using a constant amount of space for the result and temporary variables
 */

int singleNumber(int* nums, int numsSize) 
{
    int ans = 0;
    for(int i = 0; i < 32; i++)
    {
        int total_bit = 0;
        for(int j = 0; j < numsSize; j++)
        {
            total_bit += (nums[j] >> i) & 1;
        }
        int bit = total_bit % 3;
        ans = ans | ((uint)bit << i);   // 注意这里需要将bit转换为无符号整数，否则在左移时可能会出现符号扩展的问题，导致结果不正确
    }
    return ans;
}