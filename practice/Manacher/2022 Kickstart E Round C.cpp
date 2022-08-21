#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ll long long
#define pll pair<ll, ll >
using namespace std;
ll A[200005];
string imsi,nex;
void manachers(string S,ll N) {
    ll r=0,p=0;
    for(int i=0;i<N;i++) {
        if(i<=r) A[i]=min(A[2*p-i],r-i);
        else A[i]=0;
        while(true) {
            if(!(i-A[i]-1>=0)) break;
            if(!(i+A[i]+1<N&&S[i-A[i]-1]==S[i+A[i]+1])) {
                if(i+A[i]+1<N) {
                    break;
                }
            }
            A[i]++;
        }
        if(i+A[i]>r){ r=A[i]+i; p=i; }
    }
}
int main(void) {
    magic;
    ll T;
    cin>>T;
    for(ll test=1;test<=T;test++) {
        ll N;
        cin>>N;
        string str, str2;
        cin>>str;
        str2 = "#";
        for(int i=0;i<N;i++) {
            str2+=str[i];
            str2+='#';
        }
        manachers(str2, N*2+1);
        ll ans_len = 0;
        for(int i=0;i<N*2+1;i++) {
            if(A[i]>=N+1) {
                /// cout<<i<<' '<<A[i]<<' '<<((i-((2*N)-i))/2)<<'\n';
                if(A[((i-((2*N)-i))/2)]==((i-((2*N)-i))/2)) {
                    ans_len = A[i];
                    break;
                }
            }
        }
        string ans = "";
        for(ll i=0;i<ans_len-N;i++) {
            ans += str[i];
        }
        reverse(ans.begin(), ans.end());
        cout<<"Case #"<<test<<": "<<ans<<'\n';
        /// cout<<"!! ans_len: "<<ans_len<<'\n';
    }
}
