/**
 * @problem: 搜索插入位置
 * @approach: 二分查找
 * @time_complexity: O(logn)
 * @space_complexity: O(1) 
 */ 

int searchInsert(int* nums, int numsSize, int target) 
{
    int left = 0;
    int right = numsSize - 1;
    int ans = numsSize;     // 如果target比数组中所有元素都大，则插入位置为数组长度

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(target <= nums[mid])
        {
            ans = mid;      // 记录当前mid位置为可能的插入位置
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}