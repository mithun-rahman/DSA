#include<bits/stdc++.h>

using namespace std;

class Dijstra
{
    private:
        vector<pair<int, int>> graph[203];
        int n, m;
        int dist[203];
        int INF = 10000000;

         void dijstra(int src)
        {
            int u, v, w, d;
            priority_queue<pair<int, int>> pq;
            for(int i = 0; i <= n; i++) {
                dist[i] = INF;
            }
            dist[src] = 0;
            pq.push({-dist[src], src});

            while(pq.size()) {
                auto top = pq.top();
                pq.pop();
                u = top.second;
                d = -top.first;
                if(dist[u] < d) continue;
                for(int i = 0; i < graph[u].size(); i++) {
                    v = graph[u][i].first;
                    w = graph[u][i].second;
                    if(dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({-dist[v], v});
                    }
                }
            }
        }


    public:
        void init()
        {
            cin >> n >> m;
            for(int i = 1; i <= m; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
            dijstra(1);
            for(int i = 1; i <= n; i++) {
                cout << i <<" " << dist[i] << endl;
            }
        }

};
/*
4 4
1 3 5
1 2 2
3 4 3
2 3 1
*/

int main()
{
    Dijstra dj;
    dj.init();
    return 0;
}
