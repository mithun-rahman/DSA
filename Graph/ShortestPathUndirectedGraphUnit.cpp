#include<bits/stdc++.h>

using namespace std;

class ShortestPath
{
    private:
        int dist[103];
        vector<int> graph[103];

    public:
        void BFS(int u)
        {
            dist[u] = 0;
            queue<int> q;
            q.push(u);
            while(q.size()) {
                int u = q.front();
                q.pop();
                for(auto v:graph[u]) {
                    if(dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        void shortest()
        {
            graph[1].push_back(2);
            graph[1].push_back(3);

            graph[2].push_back(1);
            graph[2].push_back(4);
            graph[2].push_back(5);

            graph[3].push_back(1);
            graph[3].push_back(6);

            graph[4].push_back(2);
            graph[4].push_back(5);

            graph[5].push_back(2);
            graph[5].push_back(4);
            graph[5].push_back(6);

            graph[6].push_back(3);
            graph[6].push_back(5);

            int n = 6;
            for(int i = 1; i <= n; i++) {
                dist[i] = 100000;
            }
            BFS(1);
            for(int i = 1; i <= n; i++) {
                cout << i << " " << dist[i] << endl;
            }
        }
};

int main()
{
    ShortestPath sp;
    sp.shortest();
    return 0;
}
