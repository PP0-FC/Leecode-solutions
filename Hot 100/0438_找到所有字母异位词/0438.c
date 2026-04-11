/**
 * @problem: 找到所有字母异位词
 * @approach: 定长滑动窗口
 * @time_complexity: O(n)
 * @space_complexity: O(1)
*/

int* findAnagrams(char* s, char* p, int* returnSize) {
    *returnSize = 0;
    int len_p = 0;
    int cnt_p[26] = {0};
    for(; p[len_p]; len_p++) {
        cnt_p[p[len_p] - 'a']++;
    }
    int cnt_s[26] = {0};
    int left = 0;
    int* ans = malloc(sizeof(int) * strlen(s));
    for(int right = 0; s[right]; right++) {
        cnt_s[s[right] - 'a']++;
        if(len_p > right - left + 1) {
            continue;
        }
        if(memcmp(cnt_s, cnt_p, sizeof(cnt_s)) == 0) {
            ans[(*returnSize)++] = left;
        }
        cnt_s[s[left] - 'a']--;
        left++;
    }
    return ans;
}