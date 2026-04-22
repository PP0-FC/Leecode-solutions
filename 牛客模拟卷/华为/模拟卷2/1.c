#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char s[1003][13];
char x[13];
char result[1003][13];
int result_cnt = 0;

bool is_brother(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int ascii[128] = {0};

    if(len_a != len_b)  return false;

    if(strcmp(a, b) == 0)   return false;

    for(int i = 0; i < len_a; i++) {
        ascii[a[i]]++;
        ascii[b[i]]--;
    }

    for(int i = 0; i < 128; i++) {
        if(ascii[i] != 0) {
            return false;
        }
    }

    return true;
    
}

int cmp(const void* a, const void* b) {
    return strcmp(a, b);
}

int main() {
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    scanf("%s%d", x, &k);

    for(int i = 0; i < n; i++) {
        if(is_brother(s[i], x)) {
            strcpy(result[result_cnt++], s[i]);
        }
    }

    qsort(result, result_cnt, sizeof(result[0]), cmp);

    printf("%d\n%s", result_cnt, result[k - 1]);
    
    return 0;
}

