#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char stack_left[200008];
char stack_right[200008];
char s[200008];
char result[200008];

bool is_backspace(char* s) {
    if(strcmp(s, "backspace") == 0) {
        return true;;
    }
    else {
        return false;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    int index = 0;
    while(s[index] != '\0') {
        if(s[index] == 'I') {
            break;
        }
        index++;
    }

    int sp1 = 0, sp2 = 0;
    for(int i = 0; i < index; i++) {
        stack_left[sp1++] = s[i];
    }
    for(int i = n - 1; i > index; i--) {
        stack_right[sp2++] = s[i];
    }

    while(k--) {
        char cmd[10] = {0};
        scanf("%s", cmd);
        if(is_backspace(cmd)) {
            if(sp1 > 0 && stack_left[sp1 - 1] == '(' && sp2 > 0 && stack_right[sp2 - 1] == ')') {
                sp1--, sp2--;
            }
            else if(sp1 > 0) {
                sp1--;
            }
        }
        else {
            if(sp2 > 0) {
                sp2--;
            }
        }
    }

    int result_idx = 0;
    while(sp1 > 0) {
        result[result_idx] = stack_left[result_idx];
        result_idx++;
        sp1--;
    }
    result[result_idx++] = 'I';
    while(sp2 > 0) {
        result[result_idx] = stack_right[sp2 - 1];
        result_idx++;
        sp2--;
    }

    printf("%s", result);
    
    return 0;
}





