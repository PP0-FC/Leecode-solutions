/**
 * @problem: 三数之和
 * @approach: 外层循环遍历数组中的元素，在第i个元素是用左右指针寻找可能的组合。
 * @time_complexity: O(n^2)
 * @space_complexity: O(1)
 */ 

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int** ans = (int**)malloc(sizeof(int*) * 30000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 30000);
    int count = 0;
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1, right = numsSize - 1;
        while(left < right) {
            int sum = nums[i];
            sum += nums[left];
            sum += nums[right];
            if(sum < 0) {
                left++;
            }
            else if(sum > 0) {
                right--;
            }
            else {
                ans[count] = (int*)malloc(sizeof(int) * 3);
                ans[count][0] = nums[i];
                ans[count][1] = nums[left];
                ans[count][2] = nums[right];
                count++;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while(left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while(left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            }
        }
    }
    return ans;
}