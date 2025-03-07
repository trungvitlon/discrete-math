/*Do Viet Long - 14/06/2024*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define MAX 6000

int g[MAX][MAX], G[MAX][MAX]; // do thi g va g dao
int dist[MAX], prev[MAX], q[MAX], ans[MAX];
int vis4[MAX], vis5[MAX]; // tham cac tu sap xep 4, 5 chu cuoi 
char b[MAX][6], c[MAX][6]; // luu tu sap xep 4, 5 chu cuoi
int vis[MAX], pre[MAX], post[MAX], vp[2*MAX], cc = 1; 
int ccnum[MAX], numcc = 0, cnt = 0; // so thanh phan lien thong
typedef struct {
    int v;
    int cnt, cou;
    char s[6];
} H;
H node[MAX];

void read();
void reset(int);
void dfs1(int), previsit(int), postvisit(int), dfs2(int);
void bfs(int, int);
void makeQueue(int, int);
int check(char s1[], char s2[], int, int);

int main() {
    read();
}

void read() {
    // nhap duong di
    char sw[6], ew[6];
    char uw[6];
    scanf("%s", uw);
    scanf("%s%s", sw, ew);
    // nhap do thi
    int i = 0, j, k, s, e, u;
    while (i != 5757) {
        scanf("%s", node[i].s);
        node[i].v = i;

        if (strcmp(sw, node[i].s) == 0) s = i;
        if (strcmp(ew, node[i].s) == 0) e = i;
        if (strcmp(uw, node[i].s) == 0) u = i;
        // tao ma tran ke
        for (j = 0; j < i; j++) {
            if (check(node[j].s, node[i].s, j, i)) { 
                g[j][node[j].cnt++] = node[i].v;
                G[i][node[i].cou++] = node[j].v;
            }
            if (check(node[i].s, node[j].s, i, j)) {
                g[i][node[i].cnt++] = node[j].v;
                G[j][node[j].cou++] = node[i].v;
            }
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
        for (k = j; k > 0; k--)
            printf("%s ", node[ans[k]].s);
    }
    printf("\n\nCac thanh phan lien thong manh voi %s la:\n", uw);    
    for (k = 0; k < i; k++)
        if (ccnum[k] == ccnum[u]) {
            //cnt++;
            printf("%s ", node[k].s);
        }
    //printf("\n%d", cnt);
    printf("\n\nSo thanh phan lien thong manh la: %d\n", numcc);
}

void makeQueue(int n, int s) {
    for (int i = 0; i < n; i++) {
        dist[i] = (i != s) ? INT_MAX : 0;
        prev[i] = -1;
        if (vis[i] == 0) dfs1(i);
    }
    reset(n);
    for (int i = cc-1; i > 0; i--)
        if (vis[vp[i]] == 0) {
            numcc++;
            dfs2(vp[i]);
        }
}

void dfs1(int u) {
    vis[u] = 1;
    previsit(u);
    for (int i = 0; i < node[u].cou; i++) {
        int v = G[u][i];
        if (vis[v] == 0) dfs1(v);
    }
    postvisit(u);
}

void previsit(int v) {
    pre[v] = cc++;
}

void postvisit(int v) {
    post[v] = cc;
    vp[cc++] = v;
}

void dfs2(int u) {
    vis[u] = 1;
    ccnum[u] = numcc;
    for (int i = 0; i < node[u].cnt; i++) {
        int v = g[u][i];
        if (vis[v] == 0) dfs2(v);
    }
}

void reset(int n) {
    for (int i = 0; i < n; i++)
        vis[i] = 0;
}

void bfs(int s, int e) {
    int size = 0;
    q[size++] = s;
    dist[s] = 0;
    while(size > 0) {
        int u = q[--size];
        if (u == e) break;
        for (int i = 0; i < node[u].cnt; i++) {
            int v = g[u][i];
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q[size++] = v;
            }
        }
    }
}

int check(char* s1, char* s2, int u, int v) {
    char t1[6], t2[6], tmp;
    strcpy(t1, s1);
    strcpy(t2, s2);
    if (vis4[u] == 0) {
        vis4[u] = 1;
        for (int i = 1; i < 4; i++)
            for (int j = i+1; j < 5; j++)
                if (t1[i] > t1[j]) {
                    tmp = t1[i];
                    t1[i] = t1[j];
                    t1[j] = tmp;
                }
        strcpy(b[u], t1);
    }
    if (vis5[v] == 0) {
        vis5[v] = 1;
        for (int i = 0; i < 4; i++)
            for (int j = i+1; j < 5; j++)
                if (t2[i] > t2[j]) {
                    tmp = t2[i];
                    t2[i] = t2[j];
                    t2[j] = tmp;
            }
        strcpy(c[v], t2);
    }
    int i = 1, j = 0;
    while (i < 5) {
        if (b[u][i] != c[v][j]) 
            if (b[u][i] != c[v][++j]) return 0;
        ++i; ++j;
    }
    return 1;
}
