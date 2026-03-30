/**
 * @problem: 两数之和
 * @approach: 二分查找，利用双指针分别指向数组的开头和结尾，根据两数之和与目标值的关系移动指针
 * @time_complexity: O(logn)
 * @space_complexity: O(1)
 * @note: 题目要求返回的数组下标从1开始，因此在返回结果时需要将索引加1
 */ 

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int Index1 = 0;
    int Index2 = numbersSize - 1;
    int* ans = malloc(sizeof(int) * 2);

    while(numbers[Index1] + numbers[Index2] != target)
    {
        if(numbers[Index1] + numbers[Index2] < target)
            Index1++;
        else if(numbers[Index1] + numbers[Index2] > target)
            Index2--;
    }    

    ans[0] = Index1 + 1;
    ans[1] = Index2 + 1;

    *returnSize = 2;
    return ans;
}