#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

long long N[100008];

int cmp(const void* a, const void* b) {
    return *(long long*)a - *(long long*)b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &N[i]);
    }

    qsort(N, n, sizeof(long long), cmp);

    long long L = LONG_MAX;
    int left = 0;
    for(int right = m - 1; right < n; right++) {
        long long temp = N[right] * N[right] - N[left] * N[left];
        if(L > temp) {
            L = temp;
        }
        left++;
    }

    printf("%lld", L);
    
    return 0;
}