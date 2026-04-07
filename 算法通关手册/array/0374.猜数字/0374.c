/**
 * @problem: 猜数字大小
 * @approach: 二分查找
 * @time_complexity: O(logn)
 * @space_complexity: O(1)
 */ 

int guess(int num);

int guessNumber(int n)
{
    int left = 1;
    int right = n;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(guess(mid) == -1)
        right = mid - 1;
        if(guess(mid) == 1)
        left = mid + 1;
        if(guess(mid) == 0)
        return mid;
    }
    return -1;
}
