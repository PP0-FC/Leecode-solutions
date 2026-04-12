/**
 * @problem: 滑动窗口最大值
 * @approach: 单调队列
 * @time_complexity: O(n)
 * @space_complexity: O(n)
*/

#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* ans = malloc(sizeof(int) * (*returnSize));
    int* queue = malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < numsSize; i++) {
        while(head < tail && queue[head] <= i - k) {
            head++;
        }
        while(head <tail && nums[queue[tail - 1]] <= nums[i]) {
            tail--;
        }
        queue[tail++] = i;
        if(i >= k - 1) {
            ans[i - k + 1] = nums[queue[head]];
        }
    }
    return ans;
}