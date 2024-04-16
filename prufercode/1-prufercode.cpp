#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int N=1e5;

int deg[N],res[N];
vector<int>a[N];
bool vis[N];
int par[N];

void dfs(int u){
    vis[u]=true;
    for(int v:a[u])
        if(!vis[v]){
            par[v]=u;
            dfs(v);
        }
}

int main(){
    memset(vis,false,sizeof(vis));
    memset(par,0,sizeof(par));
    int n,i,u,v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(0);
    //cout<<deg[88]<<endl;
#if 1
    set<int>s;
    for(i=1;i<=n;i++)
        if(deg[i]==1)
            s.insert(i);
    set<int>::iterator it;
    int x,y,j=0;
    for(it=s.begin();it!=s.end();it++){
        //cout<<*it<<" ";
        y=*it;
        x=par[y];
        res[j++]=x;
        deg[x]--;
        while(x!=0&&deg[x]==1){
            if(x>y){
                s.insert(x);
                break;
            }
            else{
                //y=x;
                x=par[x];
                res[j++]=x;
                deg[x]--;
            }
        }
    }
    //cout<<j<<endl;
    for(i=0;i<j-1;i++)
        cout<<res[i]<<" ";

    return 0;
#endif
    
}