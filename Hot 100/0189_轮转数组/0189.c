/**
 * @problem: 轮转数组
 * @approach: 负负得正法。把数组分成两部分，A是会顺序前进的部分，B是超出了范围回到开头的部分。先将数组顺序颠倒，则A、B都到了自己的位置，但是顺序颠倒了。再分别对A、B进行顺序颠倒的操作，则回归了正常顺序。
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: k有可能超过数组长度，此时会循环，应该将k取模，不然会溢出。
 */ 

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b, *b = temp;
}

void rotate(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    int left_k = 0, right_k = k % numsSize - 1;     //k对取模，防止溢出
    int left_other = k % numsSize, right_other = numsSize - 1;
    while(left < right) {
        swap(&nums[left++], &nums[right--]);
    }
    while(left_k < right_k) {
        swap(&nums[left_k++], &nums[right_k--]);
    }
    while(left_other < right_other) {
        swap(&nums[left_other++], &nums[right_other--]);
    }
}