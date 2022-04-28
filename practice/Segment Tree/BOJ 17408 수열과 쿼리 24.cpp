#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
/// min 세그
struct segtree{
    vector<int> A, Tree;
    void init_size(int n){ /// this is 0 - based
        A.resize(n);
        int h = (int)ceil(log2(n));
        int tree_size = (1<<(h+1));
        Tree.resize(tree_size);
    }
    void init(int node,int start,int finish){
        if(start==finish) Tree[node] = start;
        else{
            init(node*2,start,(start+finish)/2);
            init(node*2+1,(start+finish)/2+1,finish);
            Tree[node] = A[Tree[node*2]]<A[Tree[node*2+1]]?Tree[node*2]:Tree[node*2+1];
        }
    }
    int query(int node,int start,int finish,int left,int right){
        if(left>finish||right<start) return -1;
        if(left<=start&&finish<=right) return Tree[node];
        int q1 = query(node*2,start,(start+finish)/2,left,right);
        int q2 = query(node*2+1,(start+finish)/2+1,finish,left,right);
        if(q1==-1) return q2;
        if(q2==-1) return q1;
        return A[q1]<A[q2]?q1:q2;
    }
    /// 히스토그램 할 때 query까지 짰었고, 17408 에서 update 새로 추가함 220429
    int update(int node, int start, int finish, int idx, int k){
        if(idx<start||finish<idx) return Tree[node];
        if(start==finish){ A[idx]=k; return Tree[node] = idx;}
        int q1 = update(node*2, start, (start+finish)/2, idx, k);
        int q2 = update(node*2+1, (start+finish)/2+1, finish, idx, k);
        if(q1==-1) return q2;
        if(q2==-1) return q1;
        return Tree[node]=(A[q1]<A[q2]?q1:q2);
    }
}sg;

int main(void){
    magic;
    int N, M;
    cin>>N;
    sg.init_size(N);
    for(int i=0; i<N;i++) {
        cin>>sg.A[i];
        sg.A[i] = -sg.A[i];
    }
    sg.init(1,0,N-1);
    cin>>M;
    for(int i=1;i<=M;i++) {
        int op, a, b;
        cin>>op>>a>>b;
        if(op==1) { /// a_i를 -b로 변경
            a--;
            sg.update(1, 0, N-1, a, -b);
        } else { /// a_i + a_j 최댓값
            a--; b--;
            int max_idx = sg.query(1,0,N-1,a,b);
            int second_max_left = (max_idx==a?-1:sg.query(1, 0, N-1, a, max_idx-1));
            int second_max_right = (max_idx==b?-1:sg.query(1, 0, N-1, max_idx+1, b));
            // cout<<"!! midx:  "<<max_idx<<' '<<-sg.A[max_idx]<<'\n';
            int ans = -sg.A[max_idx] + max((second_max_left==-1?0:-sg.A[second_max_left]), (second_max_right==-1?0:-sg.A[second_max_right]));
            // cout<<"!! "<<(second_max_left==-1?0:-sg.A[second_max_left])<<' '<<(second_max_right==-1?0:-sg.A[second_max_right])<<'\n';
            cout<<ans<<'\n';
        }
    }

}
