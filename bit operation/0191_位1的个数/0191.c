/**
 * @problem: 位1的个数
 * @approach: 使用位操作逐位检查二进制位。每次取出最低位，如果为1则计数器加1，然后将输入右移一位。
 * @time_complexity: O(1) since we are always processing 32 bits
 * @space_complexity: O(1) since we are using a constant amount of space for the result and temporary variables
 */

int hammingWeight(int n) 
{
    int cnt = 0;
    while(n > 0)
    {
        int bit = n & 1;
        if(bit == 1)
        {
            cnt++;
        }
        n >>= 1;
    }
    return cnt;
}