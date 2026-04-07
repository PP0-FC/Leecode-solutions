/**
 * @problem: 移动所有零到末尾
 * @approach: 双指针法
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */
void moveZeroes(int* nums, int numsSize) 
{
    int temp;
    int n = numsSize;
    int *right = &nums[0], *left = &nums[0];
    for(int i = 0 ; i < n ; i++)
    {
        //当右指针不为零时，交换左右指针所指数的值
        if(*right != 0)
        {
            temp = *left;
            *left = *right;
            *right = temp;

            left++;
        }
        //否则左指针不懂，右指针＋1
        right++;
    }
}