/*Do Viet Long - 14/06/2024*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define MAX 6000

int a[MAX][MAX]; 
int dist[MAX], prev[MAX], q[MAX], ans[MAX];
int vis[MAX], qu[MAX], cc = 0; // so lien thong 
typedef struct {
    int v;
    int cnt;
    char s[6];
} G;
G node[MAX];

void read();
void explore(int); // kiem tra lt bang dfs
void bfss(int); // kiem tra lien thong bang bfs
void bfs(int, int);
void makeQueue(int, int);
int check(char s1[], char s2[]);

int main() {
    read();
}

void read() {
    // nhap duong di
    char sw[6], ew[6];
    scanf("%s%s", sw, ew);

    int i = 0, j, s, e;
    while (i != 5757) {
        scanf("%s", node[i].s);
        node[i].v = i;
        
        if (strcmp(sw, node[i].s) == 0) s = i;
        if (strcmp(ew, node[i].s) == 0) e = i;
        // tao ma tran ke
        for (j = 0; j < i; j++)
            if (check(node[j].s, node[i].s)) {
                a[i][node[i].cnt++] = node[j].v;
                a[j][node[j].cnt++] = node[i].v;
            }
        ++i;
    }
    makeQueue(i, s);
    bfs(s, e);
    if (prev[e] == -1)
        printf("NOT FOUND\n");
    else {
        printf("Duong di tu %s den %s la:\n", sw, ew);
        j = 0;
        do {
            ans[++j] = e;
            e = prev[e];
        } while (e != s);
        ans[++j] = s;
        for (i = j; i > 0; i--)
            printf("%s ", node[ans[i]].s);
    }
    printf("\n\nSo thanh phan lien thong la: %d\n", cc);
}

void makeQueue(int n, int s) {
    for (int i = 0; i < n; i++) {
        dist[i] = (i != s) ? INT_MAX : 0;
        prev[i] = -1;
        if (vis[i] == 0) {
            cc++;
            explore(i);
        }       
    }
}

void explore(int u) {
    vis[u] = 1;
    for (int i = 0; i < node[u].cnt; i++) {
        int v = a[u][i];
        if (vis[v] == 0)
            explore(v);
    }
}

void bfss(int s) {
    int size = 0;
    qu[size++] = s;
    vis[s] = 1;
    while (size > 0) {
        int u = qu[--size];
        for (int i = 0; i < node[u].cnt; i++) {
            int v = a[u][i];
            if (vis[v] == 0) {
                vis[v] = 1;
                qu[size++] = v;
            }
        }
    }
    cc++;
}

void bfs(int s, int e) {
    int size = 0;
    q[size++] = s;
    dist[s] = 0;
    while(size > 0) {
        int u = q[--size];
        if (u == e) break;
        for (int i = 0; i < node[u].cnt; i++) {
            int v = a[u][i];
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q[size++] = v;
            }
        }
    }
}

int check(char* s1, char* s2) {
    int i = 0, cnt = 0;
    while (i < 5) {
        if (s1[i] != s2[i])
            cnt++;
        i++;
    }
    if (cnt == 1) return 1;
    return 0;
}
