/**
 * @problem: 查找目标元素
 * @approach: 二分查找
 * @time_complexity: O(logn)
 * @space_complexity: O(1)
 * @note: left + (right - left) / 2弹道偏左，left + (right - left + 1) / 2则弹道偏右。
*/

int search(int* nums, int numsSize, int target) 
{
    int left = 0;
    int right = numsSize - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;    //我称之为弹道偏左
        if(target < nums[mid])
            right = mid - 1;
        else if(target > nums[mid])
            left = mid + 1;
        else if(target == nums[mid])
            return mid;
    }
    return -1;
}