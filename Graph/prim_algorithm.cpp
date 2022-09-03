#include<bits/stdc++.h>

using namespace std;

class Prim
{
    private:
    bool visit[102];
    int dist[102];
    int parent[102];
    int INF = 100000;

    vector<pair<int, int>> graph[102];

    void algorithm(int n, int src)
    {
        dist[src] = 0;
        priority_queue<pair<int, int>> pq;

        pq.push({-dist[src], src});

        int mn, pos;
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            int u = top.second;

            visit[u] = 1;
            for(auto it:graph[u]) {
                int v = it.first;
                int w = it.second;

                if(visit[v]) continue;
                if(dist[v] > w) {

                    dist[v] = w;
                    parent[v] = u;
                    pq.push({-dist[v], v});
                }
            }
        }
    }

    public:
    void prim()
    {
        memset(visit, 0, sizeof visit);
        memset(parent, -1, sizeof parent);
        for(int i = 0; i <= 100; i++) {
            dist[i] = INF;
        }
        int n, u, v, w;
        n = 7;
        for(int i = 1; i <= n; i++) {
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        algorithm(6, 0);
        for(int i = 1; i < 6; i++) {
            cout << parent[i] << " " << i << endl;
        }
    }
};
/*
 0 1 5
 0 2 10
 0 3 100
 1 3 50
 1 4 200
 3 4 250
 4 5 50
*/

int main()
{
    Prim pm;
    pm.prim();
    return 0;
}
