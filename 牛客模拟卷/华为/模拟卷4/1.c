#include <stdio.h>

int next_node[1008];

int main() {
    int n, head, k; 
    scanf("%d%d", &n, &head);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        next_node[a] = next_node[b];
        next_node[b] = a;
    }
    scanf("%d", &k);

    if(k == head) {
        head = next_node[head];
    }
    else {
        int cur = head;
        for(int i = 0; i < n - 1; i++) {
            int next = next_node[cur];
            if(next == k) {
                next_node[cur] = next_node[next];
            }
            cur = next;
        }
    }

    int is_first = 1;
    int ans = head;
    for(int i = 0; i < n - 1; i++) {
        if(!is_first) {
            printf(" ");
        }
        is_first = 0;
        printf("%d", ans);
        ans = next_node[ans];
    }
    
    return 0;
}