#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int r, c;
        int fx[5] = {0, 0, +1, -1};
        int fy[5] = {+1, -1, 0, 0};

        void DFS(int x, int y, vector<vector<int>>& heights, int prev, vector<vector<bool>> &visit)
        {
            if(x < 0 || y < 0 || x > r || y > c) return ;
            if(visit[x][y] || heights[x][y] < prev) return ;

            visit[x][y] = 1;

            for(int i = 0; i < 4; i++) {
                DFS(x+fx[i],y+fy[i], heights, heights[x][y], visit);
            }
        }

    public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 0) return {};

        r = heights.size() - 1;
        c = heights[0].size() - 1;

        vector<vector<bool>> pacific(r+1 , vector<bool> (c+1, 0));
        vector<vector<bool>> atlantic(r+1 , vector<bool> (c+1, 0));

        for(int i = 0; i <= c; i++) {
            DFS(0, i, heights, heights[0][i], pacific);
            DFS(r, i, heights, heights[r][i], atlantic);
        }
        for(int i = 0; i <= r; i++) {
            DFS(i, 0, heights, heights[i][0], pacific);
            DFS(i, c, heights, heights[i][c], atlantic);
        }

        vector<vector<int>> res;

        for(int i = 0; i <= r; i++) {
            for(int j = 0; j <= c; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    vector<int> temp = {i, j};
                    res.push_back(temp);
                }
            }
        }
        return res;

    }
};

int main()
{
    Solution ss;
    vector<vector<int>> vt;
    vt ={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vt = ss.pacificAtlantic(vt);
    for(int i = 0; i < vt.size(); i++) {
        cout<<vt[i][0]<<", "<<vt[i][1]<<endl;
    }
    return 0;
}
