#include <stdio.h>
#include <limits.h>
#include <time.h>
#define N 150

int G[N][N], dist[N][N], L[N][N], spt[N];
int k[N];
int n, m;
int a, b, c, d, r;

typedef struct {
    int vertex;
    int key;
} H;

typedef struct {
	int f, s;
} mp;

H q[N];
int size;

int minDist(H q[], int size) {
	int min = INT_MAX, min_index;
	for (int i = 0; i < size; i++)
		if (min > q[i].key && spt[q[i].vertex] == 0)
			min = q[i].key, min_index = i;
	return min_index;
}

void dijkstra(int s) {
	for (int i = 0; i < n; i++) spt[i] = 0;
	
	size = 0;
    H x = {s, 0};
    q[size++] = x;
    for (int j = 0; j < size; j++) {
    	int index = minDist(q, size);
    	int u = q[index].vertex; spt[u] = 1;
        int du = q[index].key;
        if (du != dist[s][u]) continue;
        
        for (int i = 0; i < k[u]; i++) {
            int v = G[u][i];
            if (dist[s][v] > dist[s][u] + L[u][v]) {
                dist[s][v] = dist[s][u] + L[u][v];
                H y = {v, dist[s][v]};
                q[size++] = y;
            }
        }
    }
}

mp Q[N], par[N][N];

void setup() {
	size = 0;
	mp x = {a, b}; Q[size++] = x;
	mp y = {-1, -1}; par[a][b] = y; 
	for (int j = 0; j < size; j++) {
		int s = Q[j].f;
		int e = Q[j].s;
		mp y = {s, e};
		
		for (int i = 0; i < k[s]; i++) {
			int v = G[s][i];
			if (par[v][e].f == 0 && par[v][e].s == 0 && dist[v][e] > r) {
				par[v][e] = y;
				mp x = {v, e};
				Q[size++] = x; 
			}
		}
		
		for (int i = 0; i < k[e]; i++) {
			int u = G[e][i];
			if (par[s][u].f == 0 && par[s][u].s == 0 && dist[s][u] > r) {
				par[s][u] = y;
				mp x = {s, u};
				Q[size++] = x; 
			}
		}
		
		if (par[c][d].f || par[c][d].s) break;
	}
}

mp ans[N];

void print() {
	int j = 0;
	do {
		mp z = {c, d}; ans[++j] = z;
		int x = par[c][d].f;
		int y = par[c][d].s;
		c = x;
		d = y;
	} while (c != -1 && d != -1);
	printf("Lich di chuyen  Khoang cach\n");
	for (int i = j; i > 0; i--) {
		int u = ans[i].f;
		int v = ans[i].s;
		printf("%6d  %d           %d\n", u, v, dist[u][v]);
	}
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
        G[u][k[u]++] = v; 
		G[v][k[v]++] = u;
        L[u][v] = w; 
		L[v][u] = w;
    }
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &r);
    
    for (int u = 0; u < n; u++) {
    	for (int v = 0; v < n; v++)
        	dist[u][v] = (u != v) ? INT_MAX : 0;
    }
	for (int i = 0; i < n; i++) dijkstra(i);
    
    setup();
    
    print();
    
    return 0;
}

/*
10 12
0 4 10
0 9 11
1 4 9
2 6 5
2 8 1
3 4 11
3 6 5
4 5 2
5 7 9
7 8 3
7 9 10
8 9 4
1 3
3 4
7
*/
