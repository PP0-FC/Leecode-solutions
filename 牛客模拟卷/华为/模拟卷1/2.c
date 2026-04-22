#include <stdio.h>

int a[10][10];
int dp[10][100];

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N, M;
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < M; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        // 规定状态上限，即一行有多少种状态
        int max_state = 1 << M;

        // 给dp数组赋初值
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j < max_state; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;

        for(int i = 1; i <= N; i++) {
            for(int cur_s = 0; cur_s < max_state; cur_s++) {
                if((cur_s & cur_s >> 1) != 0) {
                    continue;
                } 

                int cur_sum = 0;
                for(int j = 0; j < M; j++) {
                    if(cur_s >> j & 1) {
                        cur_sum += a[i][j];
                    }
                }

                for(int pre_s = 0; pre_s < max_state; pre_s++) {
                    if(dp[i - 1][pre_s] == -1)  continue;
                    if((cur_s & pre_s) != 0)    continue;
                    if((cur_s >> 1 & pre_s) != 0)   continue;
                    if((cur_s << 1 & pre_s) != 0)   continue;

                    int new_s = dp[i - 1][pre_s] + cur_sum;
                    if(new_s > dp[i][cur_s]) {
                        dp[i][cur_s] = new_s;
                    }
                }
            }
        }

        int ans = 0;
        for(int s = 0; s < max_state; s++) {
            if(dp[N][s] > ans) {
                ans = dp[N][s];
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}



