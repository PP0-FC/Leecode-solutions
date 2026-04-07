/**
 * @problem: 两个数组的交集
 * @approach: 分离双指针，先对两个数组进行排序，然后使用两个指针分别指向两个数组的开头，根据指针所指元素的大小关系移动指针，找到相同的元素并加入结果数组中
 * @time_complexity: O(m + n)，其中 m 和 n 分别是两个数组的长度。
 * @space_complexity: O(min(m, n))，结果数组的大小不会超过较短数组的长度。
 * @note: 题目要求结果数组中的元素不重复，因此在添加元素到结果数组之前需要进行检查，确保不添加重复的元素。
 */
int cmp(const void* a, const void* b) 
{
    return *(int*)a - *(int*)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    // 对两个数组进行排序
    qsort(nums1 , nums1Size , sizeof(int) , cmp);
    qsort(nums2 , nums2Size , sizeof(int) , cmp);

    int Index1 = 0;
    int Index2 = 0;
    *returnSize = 0;    // 初始化结果数组的大小为0（用*returnSize作为返回数组的下标很方便）

    int* ans = malloc(sizeof(int) * (nums1Size));
    memset(ans , 0 , sizeof(int) * (nums1Size));    // 注意要将结果数组初始化为0，以便后续检查重复元素

    while(Index1 < nums1Size && Index2 < nums2Size)
    {
        int num1 = nums1[Index1] , num2 = nums2[Index2];
        if(num1 == num2)
        {
            if((*returnSize) == 0 || ans[*returnSize - 1] != num1)
            {
                ans[(*returnSize)++] = num1;
                
            }
            //下标右移应当放在if语句外面，否则当两个数组中有重复元素时，会导致指针停留在相同位置，进入死循环
            Index1++;
            Index2++;
        }
        else if(num1 < num2)    Index1++;
        else if(num1 > num2)    Index2++;
    }

    return ans;
}