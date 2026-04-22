#include <stdio.h>
#include <stdbool.h>

char grid[1005][1005];

bool visit_s[1005][1005];
bool visit_e[1005][1005];

int qx[1000005];
int qy[1000005];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int sx = -1, sy = -1, ex = -1, ey = -1;
    for(int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'S') {
                grid[i][j] = '.';
                sx = i, sy = j;
            }
            if(grid[i][j] == 'E') {
                grid[i][j] = '.';
                ex = i, ey = j;
            }
        }
    }

    int head = 0, tail = 0;
    qx[tail] = sx;
    qy[tail++] = sy;
    visit_s[sx][sy] = true;

    while(head < tail) {
        int cx = qx[head], cy = qy[head++];
        for(int i = 0; i < 4; i++) {
            int nx,ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m
                && !visit_s[nx][ny]
                && grid[nx][ny] == '.') {
                visit_s[nx][ny] = true;
                qx[tail] = nx;
                qy[tail++] = ny;
            }
        }
    }

    head = 0, tail = 0;
    qx[tail] = ex;
    qy[tail++] = ey;
    visit_e[ex][ey] = true;

    while(head < tail) {
        int cx = qx[head], cy = qy[head++];
        for(int i = 0; i < 4; i++) {
            int nx,ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if(nx >= 0 && nx <n && ny >= 0 && ny < m
                && !visit_e[nx][ny]
                && grid[nx][ny] == '.') {
                visit_e[nx][ny] = true;
                qx[tail] = nx;
                qy[tail++] = ny;
            }
        }
    }

    if(visit_s[ex][ey]) {
        printf("YES");
        return 0;
    }

    bool row_s[1005] = {0}, col_s[1005] = {0};
    bool row_e[1005] = {0}, col_e[1005] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visit_s[i][j]) {
                row_s[i] = true;
                col_s[j] = true;
            }
            if(visit_e[i][j]) {
                row_e[i] = true;
                col_e[j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(row_s[i]) {
            if(row_e[i] || (i > 0 && row_e[i - 1]) || (i < n - 1 && row_e[i + 1])) {
                printf("YES");
                return 0;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(col_s[i]) {
            if(col_e[i] || (i > 0 && col_e[i - 1]) || (i < m - 1 && col_e[i + 1])) {
                printf("YES");
                return 0;
            }
        }
    }
    
    printf("NO");
    return 0;
}





