/**
 * @problem: 最大子数组和
 * @approach: 贪心算法，当前缀和位负数时，舍弃前缀和的所有元素。
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 

#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int cur_sum = 0;
    int max_sum = INT_MIN;
    for(int i = 0; i < numsSize; i++) {
        cur_sum += nums[i];
        if(max_sum < cur_sum) {
            max_sum = cur_sum;
        }
        if(cur_sum < 0) {
            cur_sum = 0;
        }
    }
    return max_sum;
}