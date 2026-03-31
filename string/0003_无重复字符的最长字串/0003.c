/**
 * @problem: 无重复字符的最长字符串
 * @approach: 不定长滑动窗口
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: 题目中字符串只包含ASCII字符，当字符作为数组下标时，会返回对应的ASCII值，因此可以使用一个长度为128的数组来记录每个字符出现的次数。
*/
int lengthOfLongestSubstring(char* s) 
{
    int left = 0;
    int right = 0;
    int max_len = 0;
    int count[128] = {0};

    while(s[right] != '\0' )
    {
        count[s[right]]++;
        
        // 要进行去重操作，直到窗口内没有重复字符为止
        while(count[s[right]] > 1)
        {
            char ch = s[left];
            count[ch]--;
            left++;
        }

        int len = (right - left) + 1;
        if(len > max_len)
        {
            max_len = len;
        }
        
        //记录完之后，右指针继续向右移动
        right++;
    }    
    return max_len;
}