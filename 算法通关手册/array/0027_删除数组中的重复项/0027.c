/**
 * @problem: 删除数组中的重复项
 * @approach: 快慢双指针，快指针用于遍历数组，慢指针用于记录不重复元素的位置，当快指针遇到不重复的元素时，将其与慢指针后一个位置的元素交换，并将慢指针向前移动一位
 * @time_complexity: O(n)
 * @space_complexity: O(1) 
 */ 

void swap(int* a ,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int removeDuplicates(int* nums, int numsSize) 
{
    int slow = 0;
    int fast = 1;
    for(int i = 1 ; i < numsSize ; i++)
    {
        if(nums[slow] != nums[fast])
        {
            swap(&nums[++slow] , &nums[fast++]);    // 注意要先将慢指针向前移动一位，再与快指针交换元素
        }
        else fast++;
    }
    return slow + 1;    // 返回元素个数而不是下标，慢指针所在位置的索引加1
}