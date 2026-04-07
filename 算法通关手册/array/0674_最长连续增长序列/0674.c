/**
 * @problem: 最长连续递增序列
 * @approach: 不定长滑动窗口 / 快慢指针
 * @time_complexity: O(n)
 * @space_complexity: O(1)
*/

int findLengthOfLCIS(int* nums, int numsSize) 
{
    int left = 0;
    int max_len = 0;

    for(int right = 0 ; right < numsSize ; right++)
    {
        // 递增序列被打断了，将左指针移动到当前元素的位置，重新开始计算新的递增序列。
        if(right > 0 && nums[right] <= nums[right - 1])
        {
            left = right;
            continue;
        }
        
        int cur_len = (right - left) + 1;
        if(cur_len > max_len)
        {
            max_len = cur_len;
        }
    }    

    return max_len;
}