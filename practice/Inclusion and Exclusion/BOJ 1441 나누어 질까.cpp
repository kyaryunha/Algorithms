#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
using ll = long long;

ll gcd(ll x,ll y){ return y==0?x:gcd(y,x%y); }
ll lcm(ll x,ll y){ return x/gcd(x,y)*y; }

ll ans;
vector<ll> arr;
set<ll> st;

int main(void){
    magic;
    ll N,L,R;
    cin>>N>>L>>R; L--;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        st.insert(x);
    }
    for(const long long &p:st){
        arr.push_back(p);
    }
    ll asiz = arr.size();
    for(ll i=1;i<=asiz;i++){
        vector<bool> perm(asiz,false);
        for(ll j=0;j<i;j++) perm[j] = true;
        reverse(perm.begin(),perm.end());
        do{
            bool overflow = false;
            ll num = 1;
            for(ll j=0;j<asiz;j++)
                if(perm[j]){
                    num = lcm(num,arr[j]);
                    if(num>1000000000)
                        overflow = true;
                }
            if(overflow) continue;
            if(i%2) ans += (R/num - L/num);
            else ans -= (R/num - L/num);
        }while(next_permutation(perm.begin(),perm.end()));
    }
    cout<<ans;
}
