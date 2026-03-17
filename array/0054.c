/**
 * @problem: 0054 Spiral Matrix (螺旋矩阵)
 * @language: C
 * @approach: 模拟法 / 设定方向数组
 * @time_complexity: O(m * n), 必须遍历矩阵中的每个元素。
 * @space_complexity: O(m * n), 使用了一个同等大小的 visited 数组来记录访问状态。
 * * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) 
{
    //定义转向矩阵，用来确定行走方向。按行分为右、下、左、上。
    int direction[4][2] = {{0,1} , {1,0} , {0,-1} , {-1,0}};  
    
    //获取矩阵总维度，并初始化访问状态数组
    int rows = matrixSize;
    int columns = matrixColSize[0];
    int visited[rows][columns];
    memset(visited , 0 ,sizeof(visited));

    //为返回结果分配内存
    int *order = malloc(sizeof(visited));
    int total = rows*columns;
    *returnSize = total;

    // 初始化起点状态
    int curr_row = 0 , curr_column = 0;  //从[0][0]起步
    int direction_Index = 0;   //设置方向向右
    int next_row,next_col;

    //开始模拟行走过程
    for(int i = 0 ; i<total ; i++)
    {
        // 记录当前位置的值，并标记为已访问。
        order[i] = matrix[curr_row][curr_column];
        visited[curr_row][curr_column] = true;

        // 探查下一步的坐标,并判断是否会越界。
        next_row = curr_row + direction[direction_Index][0];
        next_col = curr_column + direction[direction_Index][1];
        if(next_row >= rows || next_row < 0 || next_col >= columns || next_col < 0 || visited[next_row][next_col])
        {
            // 撞墙了，顺时针右转 90 度
            direction_Index = (direction_Index+1)%4;   //取模运算让Index可以在0~3循环
        }

        // 真正迈出步伐
        curr_row += direction[direction_Index][0];
        curr_column += direction[direction_Index][1];
    }
    return order;
}