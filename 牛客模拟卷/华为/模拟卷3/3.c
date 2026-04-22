#include <stdio.h>
#include <string.h>

char s[200008];
char t[200008];

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%s%s", s, t);

        int index = 0;
        int len_s = strlen(s);
        int len_t = strlen(t);
        for(int i = 0; i < len_s; i++) {
            if(index < len_t) {
                if(s[i] == t[index] || s[i] == '?') {
                    s[i] = t[index];
                    index++;
                }
            }
            else if(s[i] == '?') {
                s[i] = 'a';
            }
        }
        if(index == len_t) {
            printf("YES\n%s\n", s);
        }
        else {
            printf("NO\n");
        }
    }
    
    return 0;
}