/**
 * @problem: 最小覆盖字串
 * @approach: 不定长滑动窗口
 * @time_complexity: O(n+m)
 * @space_complexity: O(1)
 */ 

 #include <stdlib.h>

bool is_cover(int* cnt_s, int* cnt_t) {
    for(int i = 'A'; i <= 'Z'; i++) {
        if(cnt_s[i] < cnt_t[i]) {
            return false;
        }
    }
    for(int j = 'a'; j <= 'z'; j++) {
        if(cnt_s[j] <cnt_t[j]) {
            return false;
        }
    }
    return true;
}

char* minWindow(char* s, char* t) {
    if(strlen(s) < strlen(t)) {
        return "";
    }

    int cnt_s[128] = {0};
    int cnt_t[128] = {0};
    int ans_left = -1, ans_right = strlen(s);
    int left = 0;
    for(int i = 0; t[i]; i++) {
        cnt_t[t[i]]++;
    }
    for(int right = 0; s[right]; right++) {
        cnt_s[s[right]]++;
        while(is_cover(cnt_s, cnt_t)) {
            if(right - left < ans_right - ans_left) {
                ans_right = right;
                ans_left = left;
            }
            cnt_s[s[left]]--;
            left++;
        }
    }
    if(ans_left == -1) {
        return "";
    }
    s[ans_right + 1] = '\0';
    return  &s[ans_left];
}