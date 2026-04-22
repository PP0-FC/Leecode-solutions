#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long a[305][605];
long long dp[305][605];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2 * i - 1; j++) {
            scanf("%lld", &a[i][j]);
            dp[i][j] = LLONG_MIN;
        }
    }

    dp[1][1] = a[1][1];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 2 * i - 1; j++) {
            if(dp[i][j] != LLONG_MIN) {
                if(dp[i + 1][j] < dp[i][j] + a[i + 1][j]) {
                    dp[i + 1][j] = dp[i][j] + a[i + 1][j];
                }
                if(dp[i + 1][j + 1] < dp[i][j] + a[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j] + a[i + 1][j + 1];
                }
                if(dp[i + 1][j + 2] < dp[i][j] + a[i + 1][j + 2]) {
                    dp[i + 1][j + 2] = dp[i][j] + a[i + 1][j + 2];
                }
            }
        }
    }

    long long max_ans = LLONG_MIN;

    for(int j = 1; j <= 2 * n - 1; j++) {
        if(abs(j - n) <= k) {
            if(max_ans < dp[n][j]) {
                max_ans = dp[n][j];
            }
        }
    }

    printf("%lld", max_ans);
    
    return 0;
}