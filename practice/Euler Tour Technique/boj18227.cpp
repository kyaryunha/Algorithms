#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define mod 1000000007
#define ll long long
using namespace std;
ll N,M,C;
ll arr[200005];
ll depth[200005];
vector<int> adj[200005];
ll in[200005], out[200005];
int cnt;
ll tree[800005];

void update(int node,int idx,ll val,int start,int finish){
    if(idx<start||finish<idx) return;
    tree[node] += val;
    if(start!=finish){
        update(node*2,idx,val,start,(start+finish)/2);
        update(node*2+1,idx,val,(start+finish)/2+1,finish);
    }

}

int query(int node,int le,int ri,int start,int finish){
    if(ri < start||finish < le) return 0;
    if(le<=start&&finish<=ri) return tree[node];
    return query(node*2,le,ri,start,(start+finish)/2) + query(node*2+1,le,ri,(start+finish)/2+1,finish);
}

void dfs(int u, int par, int dep){
    in[u] = ++cnt;
    depth[u] = dep;
    for(int &v:adj[u]){
        if(v==par) continue;
        dfs(v,u,dep+1);
    }
    out[u] = cnt;
}

int main(void){
    magic;
    cin>>N>>C;
    for(int i=1;i<N;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(C,-1,1);
    int Q;
    cin>>Q;

    for(int i=1;i<=Q;i++){
        int x,a;
        cin>>x>>a;
        if(x==1){
            update(1,in[a],1,1,N);
        }
        else{
            cout<<(depth[a]*query(1,in[a],out[a],1,N))<<'\n';
        }

    }

}
