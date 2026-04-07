/**
 * @problem: 子数组最大平均数
 * @approach: 定长滑动窗口
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 * @note: 题目中要求返回一个浮点数，因此需要将sum定义为double类型，以避免整数除法导致的精度问题。
*/

double findMaxAverage(int* nums, int numsSize, int k) 
{
    double sum = 0;
    double max_aver = 0;

    for(int i = 0 ; i < k ; i++)
    {
        sum += nums[i];
    }
    max_aver = sum / k;

    for(int i = k ; i < numsSize ; i++)
    {
        sum += nums[i];
        sum -= nums[i-k];
        double aver = sum / k;

        if(aver > max_aver)
        {
            max_aver = aver;
        }
    }  
    return max_aver;  
}