#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define pii pair<int,int>
#define pll pair<ll,ll>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define forn(i,n) for(int i=1;i<=n;i++)
#define forRn(i,n) for(int i=n;i>=1;i--)
#define forz(i,n) for(int i=0;i<n;i++)
#define forRz(i,n) for(int i=n-1;i>=0;i--)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define forRab(i,a,b) for(int i=a;i>=b;i--)
#define mod 1000000007
#define has 251
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
int lcm(int x,int y){ return x/gcd(x,y)*y; }
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N,M,K,test;
int a,b,c,now,past,gesu,chk,start,mini,maxi,sum,sz;
int cnt[1000005],ans[100005];
string str,str2;
int A[100005],B[100005];
struct Query{
    int lo,hi,idx;
    Query(int lo,int hi,int idx) : lo(lo),hi(hi),idx(idx){}
};
void _add(int x)
{
    if(cnt[x]) B[cnt[x]]--;
    cnt[x]++;
    B[cnt[x]]++;
    chk = max(chk,cnt[x]);
}
void _erase(int x)
{
    B[cnt[x]]--;
    if(cnt[x]==chk&&!B[cnt[x]]) chk--;
    cnt[x]--;
    B[cnt[x]]++;
}
vector<Query> query;
int main(void)
{
    magic;
    cin>>N;
    forn(i,N) cin>>A[i];
    cin>>M;
    forn(i,M)
    {
        int x,y; cin>>x>>y;
        query.emplace_back(x,y,i);
    }
    sz = sqrt(N);
    sort(query.begin(),query.end(),[](Query x,Query y){
         int xi = x.hi/sz;
         int yi = y.hi/sz;
         return xi==yi?x.lo<y.lo:xi<yi;
    });
    int lo = 0, hi = 0;
    _add(A[0]);
    for(auto cur : query)
    {
        int nlo = cur.lo, nhi = cur.hi;
        forab(i,lo,nlo-1) _erase(A[i]);
        forRab(i,lo-1,nlo) _add(A[i]);
        forab(i,hi+1,nhi) _add(A[i]);
        forRab(i,hi,nhi+1) _erase(A[i]);
        ans[cur.idx] = chk;
        lo = nlo, hi = nhi;
    }
    forn(i,M) cout<<ans[i]<<'\n';
}
