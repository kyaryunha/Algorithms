#include<bits/stdc++.h>
#define ll long long
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
int N,M,K;

const int ST_MAX = 1<<21; /// N 100만 까지
struct segtree{ /// 0-based, 1-based면 1부터 입력 받게 하자. 모든 쿼리는 start, end 모두 포함한다.
    int siz;
    vector<ll> tree, lazy;
    void init(){
        siz = (ST_MAX)/2;
        tree.assign(ST_MAX, 0);
        lazy.assign(ST_MAX, 0);
    }
     void construct(){
        for(int i=siz-1; i>=1; i--)
            tree[i] = tree[i*2] ^ tree[i*2+1];
    }
    /// 구간 [start, end) 인 node의 lazy 값을 propagate
    void propagate(int node, int start, int finish) {
        /// lazy 값이 존재하면 실행
        if(lazy[node]){
            /// 리프 노드가 아니면 자식들에게 lazy 미룸
            if(start!=finish){
                lazy[node*2] ^= lazy[node];
                lazy[node*2+1] ^= lazy[node];
            }
            /// 자신에 해당하는 만큼의 값을 xor
            if( (finish - start + 1 )%2 ) tree[node] ^= lazy[node];
            lazy[node] = 0;
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
            lazy[node] ^= diff;
            propagate(node, start, finish);
            return;
        }
        if(start != finish){
            update(node*2,start,(start+finish)/2, left, right, diff);
            update(node*2+1,(start+finish)/2+1,finish, left, right, diff);
            /// 마지막에 자식들의 값을 이용하여 다시 자신의 값을 갱신
            tree[node] = tree[node*2] ^ tree[node*2+1];
        }

    }

    ll query(int start, int finish){
        return query(1, 0, siz-1, start, finish);
    }
    ll query(int node,int start,int finish,int left,int right){
        propagate(node, start, finish);
        if(right<start||finish<left) return 0;
        if(left<=start&&finish<=right) return tree[node];
        return query(node*2,start,(start+finish)/2,left,right) ^ query(node*2+1,(start+finish)/2+1,finish,left,right);
    }
}sg;

int in[ST_MAX], out[ST_MAX];
vector<int> graph[ST_MAX];
int dfs_cnt;
void dfs(int u, int par) {
    in[u] = ++dfs_cnt;
    for(int &v:graph[u]) {
        if(v!=par) {
            dfs(v, u);
        }
    }
    out[u] = dfs_cnt;
}

int main(){
    magic;
    cin>>N>>M;
    sg.init();
    for(int i=0;i<N-1;i++) {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, -1);
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        sg.tree[in[i]+sg.siz] = x;
    }
    sg.construct();
    /*
    cout<<"Init: "; for(int i=1;i<=N;i++){
        cout<<(sg.query(i,i))<<' ';
    }cout<<'\n';
    */
    while(M--){
        int op, x;
        ll y;
        cin>>op;
        if(op==1){
            cin>>x;
            cout<<sg.query(in[x], out[x])<<'\n';
        }
        else{
            cin>>x>>y;
            sg.update(in[x], out[x], y);
        }
    }
}
