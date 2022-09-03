#include<bits/stdc++.h>

using namespace std;

class Topological
{
    private:
        vector<int> graph[103];
        bool visit[103], node[103];
        stack<int> tp;
    public:
        void topoDFS(int u)
        {
            if(visit[u]) return ;
            visit[u] = 1;

            for(auto v:graph[u]) {
                topoDFS(v);
            }
            tp.push(u);
        }
        void topoBFS(int n)
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
            vector<int> vt;
            while(q.size()) {
                int u = q.front();
                q.pop();
                vt.push_back(u);
                for(auto v:graph[u]) {
                    fr[v]--;
                    if(fr[v] == 0) {
                        q.push(v);
                    }
                }
            }
            for(int i=0; i < vt.size(); i++) {
                cout << vt[i] <<" ";
            }
            cout << endl;
        }

        void topological()
        {
            int n = 5;
            graph[2].push_back(3);
            graph[3].push_back(1);

            graph[4].push_back(1);
            graph[4].push_back(0);

            graph[5].push_back(0);

            graph[5].push_back(2);

            memset(visit, 0, sizeof visit);
//
//            for(int i = 0; i <= n; i++) {
//                if(visit[i] == 0) {
//                    topoDFS(i);
//                }
//            }
//            while(tp.size()) {
//                cout << tp.top() << " ";
//                tp.pop();
//            }
//            cout << endl;
            topoBFS(n);
        }
};

int main()
{
    Topological tp;
    tp.topological();
    return 0;
}
