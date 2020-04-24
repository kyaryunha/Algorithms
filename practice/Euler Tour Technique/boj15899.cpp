#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define mod 1000000007
using namespace std;
int N,M,C;
int arr[200005];
vector<int> adj[200005];
int in[200005], out[200005];
int cnt;
vector<int> tree[800005];

void update(int node,int idx,int val,int start,int finish){
    if(idx<start||finish<idx) return;
    tree[node].push_back(val);
    if(start!=finish){
        update(node*2,idx,val,start,(start+finish)/2);
        update(node*2+1,idx,val,(start+finish)/2+1,finish);
    }

}

int query(int node,int le,int ri, int val, int start,int finish){
    if(ri < start||finish < le) return 0;
    if(le<=start&&finish<=ri) return upper_bound(tree[node].begin(), tree[node].end(), val)-tree[node].begin();
    return query(node*2,le,ri,val,start,(start+finish)/2) + query(node*2+1,le,ri,val,(start+finish)/2+1,finish);
}

void dfs(int u, int par){
    in[u] = ++cnt;
    for(int &v:adj[u]){
        if(v==par) continue;
        dfs(v,u);
    }
    out[u] = cnt;
}

int main(void){
    magic;
    cin>>N>>M>>C;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<N;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,-1);

    for(int i=1;i<=N;i++){
        update(1,in[i],arr[i],1,N);
    }

    for(int i=1;i<=4*N;i++) sort(tree[i].begin(), tree[i].end());

    int ans = 0;
    for(int i=1;i<=M;i++){
        int v,c;
        cin>>v>>c;
        int ret = query(1,in[v],out[v],c,1,N);
        ans = (ans+ret)%mod;
    }
    cout<<(ans%mod);
}
