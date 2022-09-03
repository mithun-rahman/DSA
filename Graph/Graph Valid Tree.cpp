#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        int parent[1002];
        int rank[1002];

        int FindParent(int u)
        {
            if(u == parent[u]) return u;
            return parent[u] = FindParent(parent[u]);
        }
        void Union(int u, int v)
        {
            if(rank[u] > rank[v]) {
                parent[FindParent(v)] = parent[FindParent(u)];
            }
            else if(rank[u] < rank[v]) {
                parent[FindParent(u)] = parent[FindParent(v)];
            }
            else {
                rank[u]++;
                parent[FindParent(v)] = parent[FindParent(u)];
            }
        }
    public:
        bool isTree(vector<vector<int>>& edges, int n) {

            for(int i = 0; i <= 1000; i++) {
                rank[i] = 0;
                parent[i] = i;
            }

            for(int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                if(FindParent(u) == FindParent(v)) {
                    return 0;
                }
                else {
                    Union(u, v);
                }
            }
            int prev = FindParent(1);
            for(int i = 1;i <= n; i++) {
                int curr = FindParent(i);
                if(prev != curr) return 0;
            }
            return 1;
        }
};
int main()
{
    Solution ss;
    vector<int> vt;
    vector<vector<int>> res;
    vt = {0, 1};
    res.push_back(vt);
    vt = {0, 2};
    res.push_back(vt);
    vt = {0, 3};
    res.push_back(vt);
    vt = {1, 4};
    res.push_back(vt);
    cout << ss.isTree(res, 4) << endl;
    return 0;
}
