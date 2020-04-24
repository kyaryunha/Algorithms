#include<bits/stdc++.h>
#define pii pair<int,int>
#define pci pair<char,int>
#define forz(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define inf 1e9+7

int N,M;
vector<int> tree[400005];
void update(int node, int idx, int val, int le, int ri){
    if( idx < le || ri < idx ) return;
    tree[node].push_back(val);
    if( le != ri ){
        update(node*2,idx,val,le,(le+ri)/2);
        update(node*2+1,idx,val,(le+ri)/2+1,ri);
    }
}

int query(int node, int le, int ri, int val, int start, int finish){
    if ( finish < le || ri < start ) return 0;
    if ( le <= start && finish <= ri )
        return upper_bound(tree[node].begin(),tree[node].end(),val) - tree[node].begin();
    return query(node*2,le,ri, val,start, (start+finish)/2) + query(node*2+1,le,ri,val,(start+finish)/2+1,finish);
}
int main(){
    magic;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        update(1,i,x,1,N);
    }
    for(int i=0;i<=400000;i++) sort(tree[i].begin(),tree[i].end());
    int ans = 0;
    for(int test=1;test<=M; test++){
        int i,j,k,ans;
        cin>>i>>j>>k;
        int qle = -1000000000, qri = 1000000000;
        while(qle<=qri){
            int mid = (qle+qri)/2;
            int res = query(1,i,j,mid,1,N);
            if(res<k){
                qle = mid+1;

            }
            else{
                ans = mid;
                qri = mid - 1;
            }
        }
        cout<<ans<<'\n';
    }
}
