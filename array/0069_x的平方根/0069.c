/**
 * @problem: x的平方根
 * @approach: 二分查找
 * @time_complexity: O(logn)
 * @space_complexity: O(1) 
 * @note: x = 1 的情况要特别考虑。
 */ 

int mySqrt(int x) 
{
    int left = 0;
    int right = x;
    int ans = 0;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if((long long)mid * mid <= x)       // 注意要将mid转换为long long类型，以防止乘法溢出   
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }    
    return ans;
}