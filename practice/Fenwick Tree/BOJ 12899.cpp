#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define ll long long
struct Fenwick{
    vector<int> arr;
    vector<int> tree;
    void init(int i){
        arr.assign(i+1, 0); tree.assign(i+1, 0);
    }
    int sum(int i){
        int ans = 0;
        while(i>0) ans+=tree[i],i-=(i&-i);
        return ans;
    }
    void update(int i,int diff){
        while(i<tree.size()) tree[i]+=diff,i+=(i&-i);
    }

}fw;
int main(void){
    magic;
    int N;
    cin>>N;
    fw.init(2000001); /// 200만까지 초기화
    for(int i=1;i<=N;i++) {
        int T, X;
        cin>>T>>X;
        if(T==1) { /// S에 추가할 X
            fw.update(X, 1);
        }
        else if(T==2) { /// X는 S에서 삭제해야 할 몇 번째로 작은 수?
            int le = 1, ri = 2000000;
            int ans = 0;
            while(le<=ri) {
                int mid = (le+ri)/2;
                int chk = fw.sum(mid);
                if(chk >= X) {
                    ans = mid;
                    ri = mid - 1;
                }
                else {
                    le = mid + 1;
                }
            }
            fw.update(ans, -1);
            cout<<ans<<'\n';
        }
    }
}
