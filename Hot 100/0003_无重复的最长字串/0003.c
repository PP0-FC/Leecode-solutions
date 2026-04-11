/**
 * @problem: 无重复字符的最长字符串
 * @approach: 不定长滑动窗口
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: 题目中字符串只包含ASCII字符，当字符作为数组下标时，会返回对应的ASCII值，因此可以使用一个长度为128的数组来记录每个字符出现的次数。
*/

int lengthOfLongestSubstring(char* s) {
    int* ascii = malloc(sizeof(int) * 128);
    memset(ascii, 0, sizeof(int) * 128);
    int slow = 0, fast = 0;
    int max_len = 0;
    while(s[fast] != '\0') {
        ascii[s[fast]]++;
        while(ascii[s[fast]] > 1) {
            int ch = s[slow];
            ascii[ch]--;
            slow++;
        }
        int cur_len = fast - slow + 1;
        if(max_len < cur_len) {
            max_len = cur_len;
        }
        fast++;
    }
    return max_len;
}