#include<bits/stdc++.h>
#define ll long long
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
int N,M,K;
int a,b,c;
ll d;

const int ST_MAX = 1<<21;
struct segtree{
    int siz;
    vector<ll> tree, lazy;
    void init(){
        siz = (ST_MAX)/2;
        // cout<<siz<<' '<<(ST_MAX)<<'\n';
        tree.assign(ST_MAX, 0);
        lazy.assign(ST_MAX, -1);
    }
     void construct(){
        for(int i=siz-1; i>=1; i--)
            tree[i] = tree[i*2] + tree[i*2+1];
    }
    /// 구간 [start, end) 인 node의 lazy 값을 propagate
    void propagate(int node, int start, int finish) {
        /// lazy 값이 존재하면 실행
        if(lazy[node] != -1){
            /// 리프 노드가 아니면 자식들에게 lazy 미룸
            if(start!=finish){
                lazy[node*2] = lazy[node];
                lazy[node*2+1] = lazy[node];
            }
            /// 자신에 해당하는 만큼의 값
            tree[node] = lazy[node] * (finish - start + 1);
            lazy[node] = -1;
        }
    }
    /// left, right가 기준이고 start, finish가 변하는 값
    void update(int start, int finish, ll diff){
        update(1, 0, siz-1, start, finish, diff);
    }
    void update(int node,int start,int finish,int left, int right,ll diff){
        propagate(node, start, finish);
        if(right<start||finish<left) return;
        if(left<=start&&finish<=right){
            lazy[node] = diff;
            propagate(node, start, finish);
            return;
        }
        if(start != finish){
            update(node*2,start,(start+finish)/2, left, right, diff);
            update(node*2+1,(start+finish)/2+1,finish, left, right, diff);
            /// 마지막에 자식들의 값을 이용하여 다시 자신의 값을 갱신
            tree[node] = tree[node*2] + tree[node*2+1];
        }

    }

    ll query(int start, int finish){
        return query(1, 0, siz-1, start, finish);
    }
    ll query(int node,int start,int finish,int left,int right){
        propagate(node, start, finish);
        if(right<start||finish<left) return 0;
        if(left<=start&&finish<=right) return tree[node];
        return query(node*2,start,(start+finish)/2,left,right)+query(node*2+1,(start+finish)/2+1,finish,left,right);
    }
}sg;


int in[100005], out[100005];
vector<int> adj[100005];
int cnt;
void dfs(int u, int par){
    in[u] = ++cnt;
    for(int &v:adj[u]){
        if(v==par) continue;
        dfs(v, u);
    }
    out[u] = cnt;
}

int main(){
    magic;

    cin>>N;
    sg.init();
    for(int i=1;i<=N;i++){
        sg.tree[i+sg.siz] = 1;
    }
    sg.construct();

    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        if(i==1) continue;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1, -1);

    cin>>M;
    while(M--){
        cin>>a;
        if(a==1){
            cin>>b;
            sg.update(in[b]+1,out[b],1);
        }
        else if(a==2){
            cin>>b;
            sg.update(in[b]+1,out[b],0);
        }
        else{
            cin>>b;
            cout<<(sg.query(in[b]+1,out[b]))<<'\n';
        }
    }
}
