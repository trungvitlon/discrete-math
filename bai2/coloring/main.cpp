#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int N=1e3;
int color[N], deg[N], vis[N], num[N], check[N];
vector<int> g[N];
pair<int, int> e[N];

void bfs(int, int);
void printDot(int n, int m, int color[N]);

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
        e[i] = {u, v};
    }
    
    int k = 1, cnt = 0;
    for(int i=1; i<=n; i++) {
        k = max(k, deg[i]);
        if(deg[i] == k)
            cnt++;
    }
    //cout << k << " "; 
    
    int u = 1;
    while(true) {
        if(deg[u] < k || cnt == n) // them truong hop do thi chinh quy
            break;
        u++;
    }
    //cout << u << " ";
    bfs(u, n); // sap xep thu tu dinh
    
    // gan mau cho dinh
    fill_n(vis, n+1, 0);
    for(int j=1; j<=n; j++) {
        //cout << num[u] << " ";
        //cout << vis[u] << " ";
        fill_n(check, k+2, 0);
        //u = j;
        u = num[j];
        vis[u] = 1;
        for(auto v : g[u])
            if(vis[v]) {
                check[color[v]] = 1;  
            }
        for(int i=1; i<=k+1; i++)
            if(!check[i])
                color[u] = i;
        //cout << color[u] << " ";
    }
    printDot(n, m, color);
}

void bfs(int u, int n) {
    fill_n(vis, n+1, 0);
    queue<int> q;
    q.push(u);

    int j = n; 
    num[j] = u;
    vis[u] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                num[--j] = v;
                q.push(v);
            }
        }
    }
}

void printDot(int n, int m, int color[N]) {
    string s[10];
    s[1] = "red";
    s[2] = "green";
    s[3] = "yellow";
    s[4] = "blue";
    s[5] = "purple";
    s[6] = "orchid";
    s[7] = "hotpink";
    s[8] = "chocolate";
    s[9] = "brown";
    //s[10] = "grey";

    cout << "graph dothi {" << '\n';
    for(int u=n; u>=1; u--) {
        cout << u << " [fillcolor=" << s[color[u]] << ", style=filled];" << '\n';
    }
    for(int i=0; i<m; i++)
        cout << e[i].first << " -- " << e[i].second << ";" << '\n';       
    cout << "}";
}
