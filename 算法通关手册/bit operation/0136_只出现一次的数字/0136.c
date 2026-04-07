/**
 * @problem: 只出现一次的数字
 * @approach: 使用位操作异或运算。异或运算满足交换律和结合律，因此将所有数字进行异或运算，最终结果就是只出现一次的数字。
 * @time_complexity: O(n) since we need to iterate through all the numbers in the array once
 * @space_complexity: O(1) since we are using a constant amount of space for the result and temporary variables
 */

int singleNumber(int* nums, int numsSize) 
{
    int sum = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        sum ^= nums[i];
    }
    return sum;
}