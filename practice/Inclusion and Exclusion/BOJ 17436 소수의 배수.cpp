#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
using ll = long long;
ll arr[15];
ll ans;
vector<int> perm;
int main(void){
    magic;
    ll N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++){
        perm.assign(N,0);
        for(int j=0;j<i;j++) perm[j] = 1;
        reverse(perm.begin(),perm.end());
        do{
            ll num = 1;
            for(int k=0;k<N;k++){
                if(perm[k]) num *= arr[k];
            }
            if(i%2) ans += (M/num);
            else ans -= (M/num);
        }while(next_permutation(perm.begin(),perm.end()));
    }

    cout<<ans;
    return 0;
}
