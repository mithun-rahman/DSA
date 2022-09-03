#include<bits/stdc++.h>

using namespace std;

class UnionFind
{
    private:
        int parent[103];
        int rank[102];

        int FindParent(int x)
        {
            if(x == parent[x]) return x;
            return parent[x] = FindParent(parent[x]);
        }

        void Union(int u, int v)
        {
            u = FindParent(u);
            v = FindParent(v);

            if(rank[u] > rank[v]) {
                parent[v] = u;
            }
            else if(rank[u] < rank[v]) {
                parent[u] = v;
            }
            else {
                parent[v] = u;
                rank[u]++;
            }
        }

    public:
        void init(int n)
        {
            for(int i = 1; i <= n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
            Union(2, 1);
            Union(1, 5);
            Union(4, 6);
            Union(3, 4);

            for(int i = 1; i <= n; i++) {
                cout << i << " " << FindParent(i) << endl;
            }
        }
};

int main()
{
    UnionFind uf;
    uf.init(6);
    return 0;
}
