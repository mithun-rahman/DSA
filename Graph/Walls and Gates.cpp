#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int r, c;
        bool visit[102][102];
        int dist[102][102];

        int fx[5] = {0, 0, +1, -1};
        int fy[5] = {+1, -1, 0, 0};

        void BFS(int x, int y, vector<vector<int>> &grid)
        {
            int level = 0;
            queue<pair<int, int>> q;
            q.push({x, y});
            visit[x][y] = 1;

            while(q.size()) {

                int sz = q.size();
                for(int k = 1; k <= sz; k++) {
                    auto top = q.front();
                    q.pop();
                    x = top.first;
                    y = top.second;
                    dist[x][y] = min(dist[x][y], level);

                    for(int i = 0; i < 4; i++) {
                        int a = x + fx[i];
                        int b = y + fy[i];
                        if(a < 0 || b < 0 || a > r || b > c || visit[a][b] || grid[a][b] == 100) continue;
                        else if(grid[a][b] == 0) continue;
                        visit[a][b] = 1;
                        q.push({a, b});
                    }
                }
                level = level + 1;
            }
        }

    public:
        void solve()
        {
            vector<vector<int>> grid;
            grid = {{-1, 100, 0, -1},
                    {-1, -1, -1, 100},
                    {-1, 100, -1, 100},
                    {0, 100, -1, -1}};

            for(int i = 0; i < 101; i++) {
                for(int j = 0; j < 101; j++) {
                    dist[i][j] = 102;
                }
            }
            r = grid.size() - 1;
            c = grid[0].size() - 1;
            for(int i = 0; i <= r; i++) {
                for(int j = 0; j <= c; j++) {
                    memset(visit, 0, sizeof visit);
                    if(grid[i][j] == 0) {
                        BFS(i, j, grid);
                    }
                }
            }
            for(int i = 0; i <= r; i++) {
                for(int j = 0; j <= c; j++) {
                    printf("%4d", dist[i][j]);
                }
                cout << endl;
            }
        }

};
/*
Leetcode 286
0   = gate
-1  = empty room
100 = wall
find minimum distance from each room to any gate.
*/

int main()
{
    Solution ss;
    ss.solve();
    return 0;
}
