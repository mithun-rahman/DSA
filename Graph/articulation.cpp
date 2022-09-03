#include<bits/stdc++.h>

using namespace std;

class Articulation
{
    private:
        vector<int> graph[102];
        bool visit[102], low[102], depth[102];
        int n, m;

        void DFS(int u, int p, int d)
        {
            visit[u] = 1;
            depth[u] = low[u] = d;
            int child = 0;
            for(auto v:graph[u]) {
                if(v == p) continue;
                if(visit[v] == 0) {
                    child++;
                    DFS(v, u, d+1);
                    low[u] = min(low[u], low[v]);

                    if(depth[u] <= low[v] && p != -1) {
                        cout << u << endl;
                    }
                }
                else {
                    low[u] = min(low[u], depth[v]);
                }
            }
            if(p == -1 && child > 1) {
                cout << "yes" << endl;
                cout << u << endl;
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
    Articulation ap;
    ap.init();
    return 0;
}
