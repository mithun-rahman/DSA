#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
    int n, m;
    int INF = 1000000;

    int temp[102];
    int dist[102];

    int bellmanford(vector<vector<int>> &vt, int src, int des, int k)
    {
        for(int i = 0;i < n; i++) {
            dist[i] = temp[i] = INF;
        }
        dist[src] = 0;

        for(int t = 0; t < k; t++) {
            for(auto it:vt) {
                int u = it[0];
                int v = it[1];
                int w = it[2];


                if(dist[u] + w < dist[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            for(int i = 0; i < n; i++) {
                dist[i] = temp[i];
            }
        }
        if(dist[des] >= INF) dist[des] = -1;
        return dist[des];
    }


    public:
        void solve()
        {
            n = 4;
            m = 5;
            vector<vector<int>> vt;
            for(int i = 0; i < m; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                vector<int> tm;
                tm = {u, v, w};
                vt.push_back(tm);
            }
            cout << bellmanford(vt, 0, 3, 1 + 1) << endl;
        }

};
/*
0 1 100
2 0 100
1 2 100
1 3 600
2 3 200
*/

int main()
{
//    Solution ss;
//    ss.solve() ;

    map<string, vector<string>> graph;
    graph["JFK"].push_back("KUL");
    graph["JFK"].push_back("NRT");

    graph["NRT"].push_back("JFK");


    for(auto it:graph) {
        sort(it.second.begin(), it.second.end());
        reverse(it.second.begin(), it.second.end());
    }
    vector<string> vt;

    string next = "JFK";
    vt.push_back(next);

    while(graph[next].size()) {
        int sz = graph[next].size();

        string temp = graph[next][sz - 1];
        vt.push_back(temp);
        graph[next].pop_back();
        next = temp;
    }
    for(int i = 0; i < vt.size(); i++) {
        cout << vt[i] <<" ";
    }
    return 0;
}
