/**
 * @problem: 三数之和
 * @approach: 排序 + 双指针，先对数组进行排序，然后使用一个循环遍历数组，对于每个元素，使用双指针分别指向当前元素的下一个位置和数组的末尾，根据三数之和与0的关系移动指针，找到满足条件的三元组并加入结果数组中
 * @time_complexity: O(n^2)，其中 n 是数组的长度。排序的时间复杂度为 O(nlogn)，双指针的时间复杂度为 O(n)，总的时间复杂度为 O(n^2)。
 * @space_complexity: O(k)，其中 k 是结果数组的大小。结果数组的大小取决于满足条件的三元组的数量。
 * @note: 题目要求结果数组中的三元组不重复，因此在添加三元组到结果数组之前需要进行检查，确保不添加重复的三元组。
 */
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    // 对数组进行排序
    qsort(nums , numsSize , sizeof(int) , cmp);

    int** ans = (int**)malloc(sizeof(int*) * 30000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 30000); 
    *returnSize = 0;

    for(int i = 0 ; i < numsSize - 2 ; i++)
    {
        if(nums[i] > 0)    break;   // 因为数组已经排序，如果当前元素大于0，那么后面的元素也都大于0，不可能满足三数之和为0的条件，直接退出循环
        if(i > 0 && nums[i] == nums[i-1]) continue;     // 跳过重复元素，避免添加重复的三元组

        int left = i + 1;
        int right = numsSize - 1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[left];
                ans[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // 跳过重复元素，避免添加重复的三元组
                while(left < right && nums[left] == nums[left + 1])
                    left++;
                while(left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if(sum < 0)
                left++;
            else if(sum > 0)
                right--;
        }
    }    
    return ans;
}