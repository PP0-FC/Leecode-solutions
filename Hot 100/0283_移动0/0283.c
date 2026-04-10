/**
 * @problem: 移动0
 * @approach: 快慢指针，分别指向已处理部分的尾部和待处理部分的头部。
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize) {
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++) {
        if(nums[fast] != 0) {
            swap(&nums[slow++], &nums[fast]);
        }
    }
}