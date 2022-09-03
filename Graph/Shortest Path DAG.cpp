#include<bits/stdc++.h>

using namespace std;

class ShortestPath
{
    private:
        vector<pair<int, int>> graph[203];
        int dist[204], Fr[203];

    public:

        void BFS(int u, int n)
        {
            dist[u] = 0;
            queue<int> q;
            for(int i = 0; i < n; i++) {
                if(Fr[i] == 0) {
                    q.push(i);
                }
            }
            vector<int> vt;
            while(q.size()) {
                u = q.front();
                q.pop();
                vt.push_back(u);
                for(auto it:graph[u]) {
                    int v = it.first;
                    Fr[v]--;
                    if(Fr[v] == 0) {
                        q.push(v);
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                if(dist[i] != 100000) {
                    for(auto it:graph[i]) {
                        int v = it.first;
                        int w = it.second;
                        if(dist[v] > dist[i] + w) {
                            dist[v] = dist[i] + w;
                        }
                    }
                }
            }
            cout << endl;
        }

        void DAG()
        {
            graph[0].push_back({1, 2});
            graph[0].push_back({4, 1});

            graph[1].push_back({2, 3});

            graph[2].push_back({3, 6});

            graph[4].push_back({2, 2});
            graph[4].push_back({5, 4});

            graph[5].push_back({3, 1});

            int n = 6;
            for(int i = 0; i < n; i++) {
                dist[i] = 100000;
            }
            for(int i = 0; i < n; i++) {
                for(auto it:graph[i]) {
                    Fr[it.first]++;
                }
            }
            BFS(0, n);
            for(int i = 0;i < n; i++) {
                cout << i <<" " << dist[i] << endl;
            }
        }
};

int main()
{
    ShortestPath dg;
    dg.DAG();
    return 0;
}
