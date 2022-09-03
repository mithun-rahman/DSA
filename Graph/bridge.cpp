#include<bits/stdc++.h>

using namespace std;

class Bridge
{
    private:
        vector<int> graph[102];
        bool visit[102], low[102], depth[102];
        int n, m;

        void DFS(int u, int p, int d)
        {
            visit[u] = 1;
            depth[u] = low[u] = d;
            for(auto v:graph[u]) {
                if(v == p) continue;
                if(visit[v] == 0) {
                    DFS(v, u, d+1);
                    low[u] = min(low[u], low[v]);
                    if(low[v] > depth[u]) {
                        cout << u << " " << v << endl;
                    }
                }
                else {
                    low[u] = min(low[u], depth[v]);
                }
            }
        }

    public:
        void init()
        {
            cin >> n >> m;
            for(int i = 1; i <= m; i++) {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            memset(visit, 0, sizeof visit);
            DFS(1, -1, 0);
        }
};
/*
4 4
1 2
2 3
3 4
4 2
*/

int main()
{
    Bridge bg;
    bg.init();
    return 0;
}
