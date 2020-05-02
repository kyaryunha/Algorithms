#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
using ll = long long;
#define mod 1000000007
#define INF 1023456789
#define pii pair<int,int>
#define pll pair<ll,ll>
ll U;
ll arr[26];
ll cnt[26];
pll ave[26];
string num, str;
int main(void){
    magic;
    // freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        cin>>U;
        for(ll i=0;i<26;i++){
            arr[i] = 0;
            cnt[i] = 0;
            ave[i].first = 0;
            ave[i].second = i;
        }
        for(ll i=0;i<10000;i++){
            cin>>num>>str;
            ll ssiz = str.size();
            ll skipped = max(1LL,ssiz-1);
            for(int j=0;j<ssiz;j+=skipped){
                cnt[str[j]-'A']++;
            }
        }

        for(ll i=0;i<26;i++){
            if(cnt[i] != 0){
                ave[i].first = cnt[i];
            }
            ave[i].second = i;
            // cout<<ave[i].first<<' '<<ave[i].second<<'\n';
        }
        sort(ave,ave+26);
        reverse(ave,ave+26);
        reverse(ave,ave+10);
        reverse(ave+1,ave+10);

        printf("Case #%d: ",test);
        for(ll i=0;i<10;i++){
            printf("%c",ave[i].second+'A');
        }
        printf("\n");
    }
}
