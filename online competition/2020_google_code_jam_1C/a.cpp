#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
using ll = long long;
#define mod 1000000007
#define INF 1023456789
#define pii pair<int,int>
ll N,M,K,X,Y,A,B;
ll arr[200005];
string str;
int main(void){
    magic;
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        cin>>Y>>X;
        cin>>str;
        ll ssiz = str.size();
        ll ans = INF;
        for(ll i=0;i<ssiz;i++){
            if(str[i]=='S') X--;
            else if(str[i]=='N') X++;
            else if(str[i]=='W') Y--;
            else Y++;
            if(i+1>=abs(X)+abs(Y)){
                ans = i+1;
                break;
            }
        }
        cout<<"Case #"<<test<<": ";
        if(ans==INF) cout<<"IMPOSSIBLE";
        else cout<<ans;
        cout<<'\n';
    }
}
