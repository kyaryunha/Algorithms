#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1023456789
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plll pair<ll,pll>

ll arr[100005];
ll tree[400005];
vector<pll> one;
vector<plll> two[100005];
ll ans[100005];

void init(ll node, ll le, ll ri){
    if(le==ri){
        tree[node] = arr[le];
    }
    else{
        init(node*2,le,(le+ri)/2);
        init(node*2+1,(le+ri)/2+1,ri);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(ll node, ll idx, ll val, ll le, ll ri){
    if(idx<le||ri<idx) return;
    tree[node] += val;
    if(le!=ri){
        update(node*2,idx,val,le,(le+ri)/2);
        update(node*2+1,idx,val,(le+ri)/2+1,ri);
    }
}

ll query(ll node, ll le, ll ri, ll start, ll finish){
    if ( finish < le || ri < start ) return 0;
    if ( le <= start && finish <= ri ) return tree[node];
    return query(node*2,le,ri,start,(start+finish)/2)+query(node*2+1,le,ri,(start+finish)/2+1, finish);
}


int main(void){
    magic;
    ll N;
    cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>arr[i];
    }
    init(1,1,N);
    int M;
    cin>>M;
    ll two_cnt = 0;
    one.push_back({0,0});
    for(ll i=1;i<=M;i++){
        ll a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            one.push_back({b,c});
        }
        else{
            cin>>b>>c>>d;
            two[b].push_back({two_cnt++,{c,d}});
        }
    }
    for(ll i=0;i<one.size();i++){
        if(i!=0){
            update(1,one[i].first,one[i].second-arr[one[i].first],1,N);
            arr[one[i].first] = one[i].second;
        }
        for(plll &p:two[i]){
            ans[p.first] = query(1,p.second.first,p.second.second,1,N);
        }
    }
    for(ll i=0;i<two_cnt;i++) cout<<ans[i]<<'\n';
}
