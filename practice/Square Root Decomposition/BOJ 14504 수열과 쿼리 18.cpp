#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define mod 100000007
using namespace std;

int arr[100005];
vector<int> bucket[404];

void update(int bucket_idx, int delete_val, int update_val){
    int tsiz = bucket[bucket_idx].size();
    if(delete_val!=-1){
        for(int i=0;i<tsiz;i++){
            if(bucket[bucket_idx][i]==delete_val){
                bucket[bucket_idx].erase(bucket[bucket_idx].begin()+i);
            }
        }
    }
    for(int i=0;i<tsiz;i++){
        if(bucket[bucket_idx][i]>=update_val){
            bucket[bucket_idx].insert(bucket[bucket_idx].begin()+i,update_val);
            return;
        }
    }
    bucket[bucket_idx].push_back(update_val);
}

int query(int bucket_idx, int val){
    return (bucket[bucket_idx].size())-(upper_bound(bucket[bucket_idx].begin(),bucket[bucket_idx].end(),val)-bucket[bucket_idx].begin());
}

int main(void){
    magic;
    int N;
    cin>>N;
    int sz = sqrt(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        update(i/sz,-1,arr[i]);
    }
    int M;
    cin>>M;
    for(int test = 1;test<=M;test++){
        int op,a,b,c;
        cin>>op;
        if(op==2){
            cin>>a>>b; a--;
            update(a/sz,arr[a],b);
            arr[a]=b;
        }
        else{
            cin>>a>>b>>c; a--; b--;
            int ret = 0;
            int qle = a/sz;
            int qri = b/sz;
            for(int i=qle;i<=qri;i++){
                int le = 0, ri = sz-1;
                bool except = false;
                if(i==qle&&i==qri){
                    except = true;
                    le = a, ri = b;
                }
                else if(i==qle){
                    except = true;
                    le = a, ri = (i+1)*sz-1;
                }
                else if(i==qri){
                    except = true;
                    le = i*sz, ri = b;
                }

                if(except){
                    for(int j=le;j<=ri;j++)
                        if(arr[j]>c)
                        ret++;
                }
                else{
                    ret += query(i,c);
                }
            }
            cout<<ret<<'\n';
        }
    }
}
