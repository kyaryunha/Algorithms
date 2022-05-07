#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define ll long long
#define pii pair<int, int>
vector<pii> graph[100005];
vector<pii> queries[100005];
vector<int> ancestor;
vector<bool> visited;
vector<int> ans;
struct Dsu{
    vector<int> par,siz;
    void init(int n) {
        par.resize(n+1);
        siz.resize(n+1);
        for(int i=1;i<=n;i++) par[i]=i, siz[i]=1;
    }
    int _find(int x){
        return par[x]!=x?par[x]=_find(par[x]):x;
    }
    void _union(int x, int y){
        x=_find(x),y=_find(y);
        if(x==y) return;
        if(x>y) swap(x,y);
        siz[x]+=siz[y]; par[y]=x;
    }
    int _query(int x){
        x=_find(x); return siz[x];
    }
}dsu;

void dfs(int u) {
    visited[u] = true;
    ancestor[u] = u;
    for(pii &p:graph[u]) {
        int v = p.first;
        int x = p.second;
        if(!visited[v]) {
            dfs(v);
            dsu._union(u, v);
            ancestor[dsu._find(u)] = u;
        }
    }
    for(pii &p:queries[u]) {
        int v = p.first;
        int idx = p.second;
        if(visited[v]) {
            /// cout<<"!! "<<u<<' '<<v<<' '<<ancestor[dsu._find(v)]<<'\n';
            ans[idx] = ancestor[dsu._find(v)];
        }
    }
}

int main(void){
    magic;
    int N, M;
    cin>>N;
    for(int i=1;i<=N-1;i++) {
        int u, v, x;
        cin>>u>>v;
        graph[u].push_back({v, -1});
        graph[v].push_back({u, -1});
    }
    cin>>M;
    for(int i=0;i<M;i++) {
        int u, v;
        cin>>u>>v;
        queries[u].push_back({v, i});
        queries[v].push_back({u, i});
    }
    dsu.init(N);
    ans.resize(M);
    ancestor.resize(N+1);
    visited.assign(N+1, false);
    dfs(1);
    for(int &x:ans) {
        cout<<x<<'\n';
    }
}
