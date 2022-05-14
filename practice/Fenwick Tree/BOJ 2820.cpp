#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define ll long long
#define INF 1023456789
ll arr[500005];
vector<ll> adj[500005];
ll in[500005], out[500005];
ll cnt;

struct Fenwick{
    vector<ll> tree;
    void init(ll i){
        tree.assign(i+1, 0);
    }
    ll sum(ll i){
        ll ans = 0;
        while(i>0) ans+=tree[i],i-=(i&-i);
        return ans;
    }
    void update(ll i,ll diff){
        while(i<tree.size()) tree[i]+=diff,i+=(i&-i);
    }

}fw;

void dfs(ll u, ll par) {
    in[u] = ++cnt;
    for(ll &v:adj[u]) {
        if(v==par) continue;
        dfs(v, u);
    }
    out[u] = cnt;
}
int main(void){
    magic;
    ll N, M;
    ll ans = 0;
    cin>>N>>M;
    fw.init(N);
    cin>>arr[1]; /// 상근이
    for(ll i=2;i<=N;i++) {
        ll x;
        cin>>arr[i]>>x;
        adj[x].push_back(i);
    }
    dfs(1, -1);
    for(ll i=1;i<=N;i++) {
        fw.update(in[i], arr[i]); /// 포인트 업데이트 == 구간 1개짜리긴함 
        if((in[i])!=N) fw.update(in[i]+1, -arr[i]);
    }
    for(ll i=1;i<=M;i++){
        char op;
        ll a, b;
        cin>>op;
        if(op=='p') {
            cin>>a>>b;
            fw.update(in[a]+1, b); /// 구간 업데이트
            if(out[a]!=N) fw.update(out[a]+1, -b);
        }
        else {
            cin>>a;
            cout<<fw.sum(in[a])<<'\n'; /// 포인트 쿼리
        }
    }
}
