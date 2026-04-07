/**
 * @problem: 最大连续1的个数
 * @approach: 不定长滑动窗口
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: 要注意，这里的窗口是“伸缩伸缩”的类型，和查找递增序列那种“一刀切”类型是不一样的。
 */

int longestOnes(int* nums, int numsSize, int k) 
{
    int left = 0;
    int cnt = 0;
    int max_len = 0;

    for(int right = 0; right < numsSize; right++)
    {
        if(!nums[right])    cnt++;
        //“伸缩伸缩”的处理方式
        if(cnt > k)
        {
            // 当窗口内0的数量超过k时，左指针需要向右移动，直到窗口内0的数量不超过k为止。
            if(!nums[left])
            {
                cnt--;
            }
            left++;
        }

        int cur_len = (right - left) + 1;
        if(cur_len > max_len)
        {
            max_len = cur_len;
        }
    }
    
    return max_len;
}