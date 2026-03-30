/**
 * @problem: 第一个错误版本
 * @approach: 二分查找
 * @time_complexity: O(logn)
 * @space_complexity: O(1)
 * @note: true表示错误版本，对应二分法中的大于target的情况。false表示正确版本，对应二分法中的小于等于target的情况。最终返回的left即为第一个错误版本的索引。
 */

bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    int left = 1;
    int right = n;

    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid) == false)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid;
        }
    }
    return left;
}