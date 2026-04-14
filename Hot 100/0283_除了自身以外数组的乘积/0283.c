/**
 * @problem: 除了自身以外数组的乘积
 * @approach: 前缀积 * 后缀积就可以得到需要的值，所以先分别将数组元素的前缀积和后缀积存在两个数组中。
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* pre = malloc(sizeof(int) * numsSize);
    int* suf = malloc(sizeof(int) * numsSize);
    int* ans = malloc(sizeof(int) * numsSize);
    pre[0] = 1, suf[numsSize - 1] = 1;
    for(int i = 1; i < numsSize; i++) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }
    for(int i = numsSize - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] * nums[i + 1];
    }
    for(int i = 0; i < numsSize; i++) {
        ans[i] = pre[i] * suf[i];
    }
    free(pre);
    free(suf);
    *returnSize = numsSize;
    return ans;
}