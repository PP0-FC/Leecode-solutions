#include <stdio.h>

long long P[200008];
long long S[200008];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &P[i]);
    }

    S[0] = P[0];
    for(int i = 1; i < n; i++) {
        S[i] = P[i] + S[i - 1];
    }

    long long ans = 0;
    long long index = 0;
    for(int j = 1; j < n - 1; j++) {
        long long limit1 = (S[j] - 1) / 2;
        long long limit2 = 2 * S[j] - S[n - 1] - 1;
        long long limit = limit1 < limit2 ? limit1 : limit2;

        while(index < j && S[index] <= limit) {
            index++;
        }
        
        ans += index;
    }

    printf("%lld", ans);
    
    return 0;
}