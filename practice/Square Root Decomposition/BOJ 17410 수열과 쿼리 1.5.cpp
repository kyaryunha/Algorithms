#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define mod 100000007
using namespace std;
int arr[200005];
vector<int> tree[400];

void update(int tree_idx, int delete_val, int update_val){
    int tsiz = tree[tree_idx].size();
    if(delete_val != -1){

        for(int i=0;i<tsiz;i++){
            if(tree[tree_idx][i] == delete_val){
                tree[tree_idx].erase(tree[tree_idx].begin()+i);
                break;
            }
        }
    }
    for(int i=0;i<tsiz;i++){
        if(tree[tree_idx][i] >= update_val){
            tree[tree_idx].insert(tree[tree_idx].begin()+i,update_val);
            return;
        }
    }
    tree[tree_idx].push_back(update_val);
    return;
}

int query(int tree_idx, int val){
    return (((tree[tree_idx].size()) - (upper_bound(tree[tree_idx].begin(), tree[tree_idx].end(), val)-tree[tree_idx].begin())));
}

int main(void){
    magic;
    int N;
    cin>>N;
    int sqrtN = sqrt(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        update((i/sqrtN),-1,arr[i]);
    }

    /**
    for(int i=0;i<10;i++){
        int tsiz = tree[i].size();
        for(int j=0;j<tsiz;j++){
            cout<<tree[i][j]<<' ';
        }
        cout<<'\n';
    } cout<<'\n';
    **/
    int M;
    cin>>M;
    for(int m_query=1;m_query<=M;m_query++){
        /// cout<<"================\n";
        int op,a,b,c;
        cin>>op;
        if(op==1){
            cin>>a>>b; a--;
            update((a/sqrtN),arr[a],b);
            arr[a] = b;
        }
        else{
            cin>>a>>b>>c; a--; b--;
            int ret = 0;
            int qle = a/sqrtN;
            int qri = b/sqrtN;
            /// cout<<"Q : "<<qle<<' '<<qri<<'\n';
            for(int i=qle;i<=qri;i++){

                int le = 0;
                int ri = sqrtN-1;

                if(qle==qri){
                    for(int j=a;j<=b;j++){
                        if(arr[j]>c)
                            ret++;
                    }
                    continue;
                }

                if(i==qle){
                    ri = (i+1)*sqrtN-1;
                    for(int j=a;j<=ri;j++){
                        if(arr[j]>c)
                            ret++;
                    }
                    continue;
                }
                if(i==qri){
                    le = i*sqrtN;
                    for(int j=le;j<=b;j++){
                        if(arr[j]>c)
                            ret++;
                    }
                    continue;
                }

                int query_ret = query(i,c);
                /// cout<<"query ret : "<<query_ret<<'\n';
                ret += query_ret;
            }
            cout<<ret<<'\n';
        }
    }
    return 0;
}
