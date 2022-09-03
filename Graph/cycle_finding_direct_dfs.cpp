#include<bits/stdc++.h>

using namespace std;

class CycleFinding
{
    private:
        vector<int> graph[103];
        bool visit[102], node[103];

    public:
        bool DFS(int u)
        {
            if(visit[u]) return 1;

            visit[u] = node[u] = 1;
            bool x = 0;
            for(auto v:graph[u]) {
                if(node[v] == 0) x = x | DFS(v);
                else if(visit[v]) x = x | 1;
            }
            visit[u] = 0;
            return x;
        }
        bool BFS_Kahn(int n)
        {
            int fr[103];
            memset(fr, 0, sizeof fr);
            for(int i = 0; i <= n; i++) {
                for(auto v:graph[i]) {
                    fr[v]++;
                }
            }
            queue<int> q;
            for(int i = 0; i <= n; i++) {
                if(fr[i] == 0) {
                    q.push(i);
                }
            }

            while(q.size()) {
                int u = q.front();
                q.pop();
                for(auto v:graph[u]) {
                    fr[v]--;
                    if(fr[v] == 0) {
                        q.push(v);
                    }
                }
            }
            int x = 1;
            for(int i = 0; i <= n; i++) {
                x = x & (fr[i] == 0);
            }
            return x^1;
        }
        bool cycle()
        {
            int n = 5;
            graph[2].push_back(3);
            graph[3].push_back(1);

            graph[4].push_back(1);
            graph[4].push_back(0);

            graph[5].push_back(0);

            graph[5].push_back(2);

            memset(visit, 0, sizeof visit);
            memset(node, 0, sizeof node);

            cout << BFS_Kahn(n) << endl;

            bool x = 0;
            for(int i = 0; i <= n; i++) {
                if(node[i] == 0) {
                    x = x | DFS(i);
                }
            }
            return x;
        }
};

int main()
{
    CycleFinding cf;
    cout << cf.cycle() << endl;
    return 0;
}
