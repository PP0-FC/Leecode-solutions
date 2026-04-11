/**
 * @problem: 接雨水
 * @approach: 左右指针
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 


// 用来比较 a,b 大小的函数
int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int trap(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int left_max = 0, right_max = 0;
    int ans = 0;
    while(left < right) {
        left_max = max(left_max, height[left]);
        right_max = max(right_max, height[right]);

        // 如果左边最高的墙比右边矮，那么左边加满水右边可以兜底
        if(left_max < right_max) {
            ans += left_max - height[left];
            left++;
        }
        // 如果右边最高的墙比左边矮，那么右边加满水左边可以兜底
        else {
            ans += right_max - height[right];
            right--;
        }
    }
    return ans;
}