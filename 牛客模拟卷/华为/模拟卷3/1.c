#include <stdio.h>

int main() {
    long long n1, n2, n3, n4;
    long long ip;
    scanf("%lld.%lld.%lld.%lld", &n1, &n2, &n3, &n4);
    scanf("%lld", &ip);

    long long ans = n1 << 24 | n2 << 16 | n3 << 8 | n4;
    long long y1, y2, y3, y4;
    y1 = ip >> 24 & 255;
    y2 = ip >> 16 & 255;
    y3 = ip >> 8 & 255;
    y4 = ip & 255;

    printf("%lld\n", ans);
    printf("%lld.%lld.%lld.%lld", y1, y2, y3, y4);
    
    return 0;
}