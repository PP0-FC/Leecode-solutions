/**
 * @problem: 大小为k且平均数大于等于3的子数组数量
 * @approach: 定长滑动窗口
 * @time_complexity: O(n)
 * @space_complexity: O(1)
*/

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) 
{
    int target = k * threshold;
    int count = 0;
    int sum = 0;

    // 先构建第一个窗口
    for(int i = 0 ; i < k ; i++)
    {
        sum += arr[i];
    }
    if(sum >= target)
        count++;
    
    // 滑动窗口
    for(int i = k ; i < arrSize ; i++)
    {
        // 移动窗口：加上新元素，减去旧元素
        sum += arr[i];
        sum -= arr[i-k];

        if(sum >= target)
            count++;
    }
    
    return count;
}