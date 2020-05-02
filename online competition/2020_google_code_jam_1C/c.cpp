#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
using ll = long long;
#define mod 1000000007
#define INF 1023456789
#define pii pair<int,int>
ll N,D;
ll arr[200005];
string str;
int main(void){
    magic;
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        cin>>N>>D;
        ll ans = 0;
        for(ll i=0;i<N;i++){
            cin>>arr[i];
        }
        sort(arr,arr+N);
        if(D==2){
            ans = 1;
            for(ll i=0;i<N-1;i++){
                if(arr[i]==arr[i+1]) ans = 0;
            }
        }
        else{
            ans = 2;
            for(ll i=0;i<N-1;i++){
                if(arr[i]==arr[i+1])
                    ans = 1;
            }
            for(ll i=0;i<N-2;i++){
                if(arr[i]==arr[i+1]&&arr[i]==arr[i+2])
                    ans = 0;
            }
            if(ans==2){
                for(ll i=0;i<N;i++){
                    if(binary_search(arr,arr+N,arr[i]*2))
                        ans = 1;
                }
            }
        }

        cout<<"Case #"<<test<<": ";
        cout<<ans;
        cout<<'\n';
    }
}
