#include<bits/stdc++.h>
#define ll long long
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
int N,M,K;
int a,b,c;
ll d;

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
                lazy[node*2] ^= 1;
                lazy[node*2+1] ^= 1;
            }
            /// 자신에 해당하는 만큼의 값을 xor
            tree[node] = (finish - start +1) - tree[node];
            lazy[node] = 0;
        }
    }
    /// left, right가 기준이고 start, finish가 변하는 값
    void update(int start, int finish){
        update(1, 0, siz-1, start, finish);
    }
    void update(int node,int start,int finish,int left, int right){
        propagate(node, start, finish);
        if(right<start||finish<left) return;
        if(left<=start&&finish<=right){
            lazy[node] ^= 1;
            propagate(node, start, finish);
            return;
        }
        if(start != finish){
            update(node*2,start,(start+finish)/2, left, right);
            update(node*2+1,(start+finish)/2+1,finish, left, right);
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
        return query(node*2,start,(start+finish)/2,left,right) + query(node*2+1,(start+finish)/2+1,finish,left,right);
    }
}sg;


int main(){
    magic;
    cin>>N>>M;
    sg.init();
    while(M--){
        cin>>a;
        if(a==0){
            cin>>b>>c;
            if(b>c) swap(b, c);
            sg.update(b,c);
        }
        else{
            cin>>b>>c;
            if(b>c) swap(b, c);
            cout<<(sg.query(b,c))<<'\n';
        }
    }
}
