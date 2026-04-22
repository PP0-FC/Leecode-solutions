#include <stdio.h>
#include <stdlib.h>

int n;
int train[15];      //火车入站顺序
int station[15];    //存放进站火车编号，火车站，模拟栈
int top = 0;        //栈顶指针
int out_seq[15];    //火车出站顺序

int result[20000][15];
int result_cnt = 0;

void dfs(int push_index, int pop_count) {
    // 递归终止条件，所有火车都出站了
    if(pop_count == n) {
        for(int i = 0; i < n; i++) {
            result[result_cnt][i] = out_seq[i];
        }
        result_cnt++;
        return;
    }

    // 出站的情况
    if(top > 0) {
        int train = station[top - 1];
        out_seq[pop_count] = station[top - 1]; 
        top--;
        dfs(push_index, pop_count + 1);
        top++;
        station[top - 1] = train;
    }

    // 入站的情况
    if(push_index < n) {
        station[top] = train[push_index];
        top++;
        dfs(push_index + 1, pop_count);
        top--;
    }
}

int cmp(const void* a, const void* b) {
    int* arr1 = (int*)a;
    int* arr2 = (int*)b;
    for(int i = 0; i < n; i++) {
        if(arr1[i] != arr2[i]) {
            return arr1[i] - arr2[i];
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &train[i]);
    }

    dfs(0, 0);

    qsort(result, result_cnt, sizeof(result[0]), cmp);

    for(int i = 0; i < result_cnt; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }
    
    return 0;
}
