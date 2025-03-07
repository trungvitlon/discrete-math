#include <stdio.h>
#define MAX 30

int a[MAX][3], vis[8][5], prev[MAX], ans[MAX], tmp[3];
const int L[3] = {10, 7, 4};
void dfs(int a[][3], int);
void print();
int min(int, int);
int e, flag = 0; // e la so thao tac

int main() {
    a[0][0] = 0;
    a[0][1] = 7;
    a[0][2] = 4;
    dfs(a, 0);
    print();
}

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

void dfs(int a[][3], int k) {
    vis[a[k][1]][a[k][2]] = 1;
    if (flag == 0 && (a[k][1] == 2 || a[k][2] == 2)) {
        printf("Day cac thao tac la:\n");
        e = k;
        flag = 1;
    }
    int i, j, H;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) 
            if (j != i && L[i] > a[k][i] && a[k][j] > 0) {
                H = min(L[i] - a[k][i], a[k][j]);
                tmp[i] = a[k][i] + H;
                tmp[j] = a[k][j] - H;
                tmp[3-j-i] = a[k][3-j-i];
                if (vis[tmp[1]][tmp[2]] == 0) {
                    a[k+1][i] = tmp[i];
                    a[k+1][j] = tmp[j];    
                    a[k+1][3-j-i] = tmp[3-j-i];
                    prev[k+1] = k;
                    dfs(a, k+1);
                }
            }
}

void print() {
    int i, k, j = 0;
    do {
        ans[++j] = e;
        e = prev[e];
    } while (e != 0);
    ans[++j] = 0;
    for (i = j; i > 0; i--) {
        k = ans[i];
        printf("%d %d %d\n", a[k][0], a[k][1], a[k][2]);
    }
}