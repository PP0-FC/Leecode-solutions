/**
 * @problem: 数字范围按位与
 * @approach: 找到left和right的公共前缀。
 * @time_complexity: O(1) since we are always processing 32 bits
 * @space_complexity: O(1) since we are using a constant amount of space for the result and temporary variables
 */

int rangeBitwiseAnd(int left, int right) 
{
    int shift = 0;
    while(left < right)
    {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}