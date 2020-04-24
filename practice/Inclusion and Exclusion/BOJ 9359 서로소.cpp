#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
using ll = long long;
vector<bool> chk;
vector<ll> prime;
void eratos(){
    chk.assign(32000,true);
    chk[1] = false;
    for(ll i=2;i<32000;i++){
        if(chk[i]){
            prime.push_back(i);
            for(ll j=i*i;j<32000;j+=i){
                chk[j] = false;
            }
        }
    }
}

int main(void){
    magic;
    int T;
    cin>>T;
    eratos();
    for(int test=1;test<=T;test++){
        ll A,B,N;
        ll ans = 0;
        cin>>A>>B>>N; A--;
        vector<ll> arr;
        for(ll &p:prime){
            if(N%p==0){
                arr.push_back(p);
                while(N%p==0) N/=p;
            }
            if(N==1) break;
        }
        if(N!=1) arr.push_back(N);
        ll asiz = arr.size();
        for(ll i=1;i<=asiz;i++){
            vector<bool> perm(asiz,false);
            for(ll j=0;j<i;j++) perm[j] = true;
            reverse(perm.begin(),perm.end());
            do{
                ll num = 1;
                for(ll j=0;j<asiz;j++)
                    if(perm[j]) num *= arr[j];

                if(i%2) ans += ((B/num) - (A/num));
                else ans -= ((B/num) - (A/num));
            }while(next_permutation(perm.begin(),perm.end()));
        }
        cout<<"Case #"<<test<<": "<<(B-A-ans)<<'\n';
    }
}
