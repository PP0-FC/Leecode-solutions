/**
 * @problem: 盛水最多的容器
 * @approach: 左右指针，向内收缩，记录每次的容积，和最大值比较。最后返回最大的容积。
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_val = 0;
    while(left < right) {
        int cur_val = 0, len = right - left;
        if(height[left] < height[right]) {
            cur_val = height[left++] * len;
        }
        else {
            cur_val = height[right--] * len;
        }
        
        if(cur_val > max_val) {
            max_val = cur_val;
        }
    }
    return max_val;
}