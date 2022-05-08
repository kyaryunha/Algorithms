#include<bits/stdc++.h>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define pii pair<int, int>
const int MAXN = 20005;
struct TarjanScc{
    vector<int> graph[MAXN];
    int up[MAXN], visit[MAXN], vtime;
    vector<int> stk;
    int scc_idx[MAXN], scc_cnt;

    vector<int> dag[MAXN]; /// start where One Index

    void init(int N) {
        stk.clear();
        scc_cnt = 0;
        for(int i=0;i<=N;i++) {
            graph[i].clear();
            up[i] = 0; visit[i] = 0; vtime = 0;
            scc_idx[i] = 0;
        }

    }

    void dfs(int nod) {
        up[nod] = visit[nod] = ++vtime;
        stk.push_back(nod);
        for (int next : graph[nod]) {
            if (visit[next] == 0) {
                dfs(next);
                up[nod] = min(up[nod], up[next]);
            }
            else if (scc_idx[next] == 0)
                up[nod] = min(up[nod], visit[next]);
        }
        if (up[nod] == visit[nod]) {
            ++scc_cnt;
            int t;
            int chk = 0;
            do {
                t = stk.back();
                dag[scc_cnt].push_back(t); ///
                stk.pop_back();
                scc_idx[t] = scc_cnt;
            } while (!stk.empty() && t != nod);
        }
    }

    void dagSort() { /// dag sort
        for(int i=1;i<=scc_cnt;i++){
            sort(dag[i].begin(),dag[i].end());
        }
        sort(dag+1,dag+scc_cnt+1);
    }

    /// find SCCs in given directed graph
    /// O(V+E), 0-index
    /// the order of scc_idx constitutes a reverse topological sort
    void get_scc(int n) {
        vtime = 0;
        memset(visit, 0, sizeof(visit));
        scc_cnt = 0;
        memset(scc_idx, 0, sizeof(scc_idx));
        for (int i = 0; i < n; ++i)
            if (visit[i] == 0) dfs(i);
    }
}scc;
int main(void){
    // magic;
    int N, M;
    while(scanf("%d %d", &N, &M)==2) {
        scc.init(2*(N+1));
        for(int i=1;i<=M;i++) {
            int x, y, rx, ry;
            scanf("%d %d", &x, &y);
            if(x<0) {
                rx = -x;
                x = rx + N; /// 절댓값 + N
            }
            else {
                rx = x + N;
            }
            if(y<0) {
                ry = -y;
                y = ry + N; /// 절댓값 + N
            }
            else {
                ry = y + N;
            }
            scc.graph[rx].push_back(y);
            scc.graph[ry].push_back(x);
        }
        scc.graph[1+N].push_back(1); /// 1은 무조건 True 여야 한다.
        scc.get_scc(2*(N+1));
        bool answer = true;
        for(int i=1;i<=N;i++) {
            if(scc.scc_idx[i]==scc.scc_idx[i+N]) {
                answer = false;
            }
        }
        puts(answer?"yes":"no");
    }
}

