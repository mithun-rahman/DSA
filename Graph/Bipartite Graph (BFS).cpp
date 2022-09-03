#include<bits/stdc++.h>

using namespace std;

class BipartiteGraph
{
    private:
        vector<int> graph[103];
        bool visit[103], color[103];

    public:
        bool ColorBFS(int u)
        {
            queue<int> q;
            q.push(u);
            color[u] = 1;
            while(q.size()) {
                u = q.front();
                q.pop();
                for(auto v:graph[u]) {
                    if(visit[v] == 0) {
                        visit[v] = 1;
                        q.push(v);
                        color[v] = color[u] ^ 1;
                    }
                    else if(color[v] == color[u]) return 0;
                }
            }
            return 1;
        }
        bool ColorDFS(int u)
        {
            visit[u] = 1;

            bool x = 1;
            for(auto v:graph[u]) {
                if(visit[v] == 0) {
                    color[v] = color[u] ^ 1;
                    x = x & (ColorDFS(v));
                }
                else if(color[u] == color[v]) return 0;
            }

            return x;
        }
        bool bipartite()
        {
            int n = 5;
            graph[1].push_back(2);
            graph[1].push_back(3);

            graph[2].push_back(1);
            graph[2].push_back(3);

            graph[3].push_back(2);
            graph[3].push_back(1);

//            graph[4].push_back(2);
//            graph[4].push_back(3);

            memset(visit, 0, sizeof visit);

            color[1] = 1;
            return ColorDFS(1);

        }
};

int main()
{
    BipartiteGraph bg;
    cout << bg.bipartite() << endl;
    return 0;
}
