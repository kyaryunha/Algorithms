#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define pii pair<int, int>
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
};

struct OfflineLCA {
    Dsu dsu;
    vector<int> graph[10005];
    vector<pii> queries[10005];
    vector<int> ancestor;
    vector<int> ans;
    void init(int N, int Q) { /// N is 1-based, Q is 0-based.
        dsu.init(N);
        for(int i=0;i<=N;i++) graph[i].clear();
        for(int i=0;i<=N;i++) queries[i].clear();
        ancestor.assign(N+1, 0);
        ans.assign(Q, 0);
    }
    void dfs(int u) {
        ancestor[u] = u;
        for(int &v:graph[u]) {
            dfs(v);
            dsu._union(u, v);
            ancestor[dsu._find(u)] = u;
        }
        for(pii &p:queries[u]) {
            int v = p.first;
            int idx = p.second;
            /// cout<<"!! "<<u<<' '<<v<<' '<<ancestor[dsu._find(v)]<<'\n';
            ans[idx] = ancestor[dsu._find(v)];
        }
    }
}olca;
vector<bool> is_root;
int main(void){
    magic;
    int T;
    cin>>T;
    for(int test=1;test<=T;test++) {
        int N, M=1;
        cin>>N;
        olca.init(N, M);
        int root=-1;
        is_root.assign(N+1, true);
        for(int i=1;i<=N-1;i++) {
            int u, v;
            cin>>u>>v;
            olca.graph[u].push_back(v);
            is_root[v] = false;
        }
        for(int i=1;i<=N;i++) if(is_root[i]) root = i;
        for(int i=0;i<M;i++) {
            int u, v;
            cin>>u>>v;
            olca.queries[u].push_back({v, i});
            olca.queries[v].push_back({u, i});
        }
        olca.dfs(root);
        for(int &x:olca.ans) {
            cout<<x<<'\n';
        }
    }
}
