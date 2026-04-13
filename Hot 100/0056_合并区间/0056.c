/**
 * @problem: 合并区间
 * @approach: 先排序，后合并。排序后区间相邻的元素就会相邻
 * @time_complexity: O(n)
 * @space_complexity: O(1)
 */ 

int cmp(const void* a, const void* b) {
    return (*((int**)a)[0]) - (*((int**)b))[0];
}

int max(int a, int b) {
    return a > b ? a : b;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize == 0) {
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int left = intervals[0][0];
    int right = intervals[0][1];
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    int** ans = malloc(sizeof(int*) * intervalsSize);
    *returnSize = 0;
    (*returnColumnSizes)[*returnSize] = 2;
    for(int i = 0; i < intervalsSize; i++) {
        if(right >= intervals[i][0]) {
            right = max(right, intervals[i][1]);
        }
        else {
            ans[*returnSize] = malloc(sizeof(int) * 2);
            ans[*returnSize][0] = left;
            ans[*returnSize][1] = right;
            (*returnColumnSizes)[(*returnSize)++] = 2;
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    ans[*returnSize] = malloc(sizeof(int) * 2);
    ans[*returnSize][0] = left;
    ans[*returnSize][1] = right;
    (*returnColumnSizes)[(*returnSize)++] = 2;
    return ans;
}