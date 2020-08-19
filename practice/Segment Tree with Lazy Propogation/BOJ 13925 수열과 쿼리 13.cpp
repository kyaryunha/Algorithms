#include<bits/stdc++.h>
#define ll long long
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
int N,M,K;
int a,b,c;
ll d;
#define mod 1000000007
#define pll pair<ll, ll>

const int ST_MAX = 1<<21;

/// description X += Y;
/// usage: X  = calc(X, Y);
pll calc(pll X, pll Y){
    if(Y.first == 0){
        return {0, Y.second};
    }
    pll ret;
    ret.first = (X.first * Y.first) % mod;
    ret.second = ( ( (X.second * Y.first) % mod ) + Y.second ) % mod;
    return ret;
}

struct segtree{
    int siz;
    vector<ll> tree;
    vector<pll> lazy;
    void init(){
        siz = (ST_MAX)/2;
        tree.assign(ST_MAX, 0);
        lazy.assign(ST_MAX, {1, 0});
    }
     void construct(){
        for(int i=siz-1; i>=1; i--)
            tree[i] = (tree[i*2] + tree[i*2+1]) % mod;
    }
    /// 구간 [start, end) 인 node의 lazy 값을 propagate
    void propagate(int node, int start, int finish) {
        /// lazy 값이 존재하면 실행
        if(lazy[node] != pll(1, 0)){
            /// 리프 노드가 아니면 자식들에게 lazy 미룸
            if(start!=finish){
                lazy[node*2] = calc(lazy[node*2], lazy[node]);
                lazy[node*2+1] = calc(lazy[node*2+1], lazy[node]);
            }
            /// 자신에 해당하는 만큼의 값
            tree[node] = (tree[node]*lazy[node].first + lazy[node].second*(finish - start +1))%mod;
            lazy[node] = {1, 0};
        }
    }
    /// left, right가 기준이고 start, finish가 변하는 값
    void update(int start, int finish, pll diff){
        update(1, 0, siz-1, start, finish, diff);
    }
    void update(int node,int start,int finish,int left, int right, pll diff){
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
            tree[node] = (tree[node*2] + tree[node*2+1]) % mod;
        }

    }

    ll query(int start, int finish){
        return query(1, 0, siz-1, start, finish);
    }
    ll query(int node,int start,int finish,int left,int right){
        propagate(node, start, finish);
        if(right<start||finish<left) return 0;
        if(left<=start&&finish<=right) return tree[node];
        return (query(node*2,start,(start+finish)/2,left,right)+query(node*2+1,(start+finish)/2+1,finish,left,right)) % mod;
    }
}sg;


int main(){
    magic;

    cin>>N;
    sg.init();
    for(int i=1;i<=N;i++){
        cin>>sg.tree[i+sg.siz];
    }
    sg.construct();

    cin>>M;
    while(M--){
        int x, y;
        ll v;
        cin>>a;
        if(a==1){
            cin>>x>>y>>v;
            sg.update(x, y, {1, v});
        }
        else if(a==2){
            cin>>x>>y>>v;
            sg.update(x, y, {v, 0});
        }
        else if(a==3){
            cin>>x>>y>>v;
            sg.update(x, y, {0, v});
        }
        else{
            cin>>x>>y;
            cout<<(sg.query(x, y))<<'\n';
        }
    }
}
