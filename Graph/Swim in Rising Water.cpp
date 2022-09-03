#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        int dist[52][52];
        int INF = 100000;

        int fx[5] = {0, 0, +1, -1};
        int fy[5] = {-1, +1, 0, 0};
        int r, c;

        int dijstra(vector<vector<int>>& grid)
        {
            priority_queue<pair<int, pair<int, int>>> pq;
            int x, y;
            dist[0][0] = grid[0][0];
            pq.push({-dist[0][0], {0, 0}});

            while(pq.size()) {
                auto top = pq.top();
                pq.pop();

                auto pp = top.second;
                x = pp.first;
                y = pp.second;

                int d = -top.first;

                if(d > dist[x][y]) continue;

                for(int i = 0; i < 4; i++) {
                    int a = x + fx[i];
                    int b = y + fy[i];

                    if(a < 0 || b < 0 || a > r || b > c) continue;

                    int w = 0;

                    if(grid[a][b] < grid[x][y]) {
                        grid[a][b] = grid[x][y];
                    }

                    w = grid[a][b] - grid[x][y];

                    if(w + dist[x][y] < dist[a][b]) {
                        dist[a][b] = w + dist[x][y];
                        pq.push({-dist[a][b], {a, b}});
                    }
                }
            }
            return dist[r][c];
        }

    public:
        int swimInWater(vector<vector<int>>& grid)
        {
            for(int i = 0; i < 51; i++) {
                for(int j = 0; j < 51; j++) {
                    dist[i][j] = INF;
                }
            }
            r = c = grid.size() - 1;

            return dijstra(grid);
        }
};

int main()
{
    Solution ss;
    vector<vector<int>> grid;
    grid = {{3,2},{0,1}};
    cout << ss.swimInWater(grid) << endl;
    return 0;
}
