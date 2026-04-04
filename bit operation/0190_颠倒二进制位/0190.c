/**
 * @problem: 颠倒二进制位
 * @approach: 使用位操作逐位颠倒二进制位。每次取出最低位，加入结果的最低位，然后将结果左移一位，输入右移一位。
 * @time_complexity: O(1) since we are always processing 32 bits
 * @space_complexity: O(1) since we are using a constant amount of space for the result and temporary variables
 */

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for(int i = 0; i < 32; i++)
    {
        uint32_t bit = n & 1;
        ans = (ans << 1) | bit;
        n >>= 1;
    }
    return ans;
}