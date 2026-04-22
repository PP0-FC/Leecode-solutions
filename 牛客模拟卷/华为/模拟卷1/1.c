#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[1008];

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int main() {
    scanf("%s", s);
    int len = strlen(s);
    qsort(s, len, sizeof(char), cmp);
    printf("%s", s);

    return 0;
}