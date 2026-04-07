/**
 * @problem: 删除数组中的元素
 * @approach: 快慢双指针，快指针用于遍历数组，慢指针用于记录不重复元素的位置，当快指针遇到不等于目标值的元素时，将其与慢指针后一个位置的元素交换，并将慢指针向前移动一位
 * @time_complexity: O(n)
 * @space_complexity: O(1) 
 */ 

int removeElement(int* nums, int numsSize, int val) 
{
    int slow = 0;
    for(int fast = 0 ; fast < numsSize ; fast++)
    {
        if(nums[fast] != val)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}