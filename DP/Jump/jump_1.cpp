#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int frogJump(int n, vector<int> &heights)
        {
            int dp[n+3];
            dp[1] = 0;
            if(n == 1) return dp[1];

            dp[2] = abs(heights[1]-heights[0]);

            for(int i = 3; i <= n; i++) {
                int x1 = dp[i-1] + abs(heights[i-1]-heights[i-2]);
                int x2 = dp[i-2] + abs(heights[i-1]-heights[i-3]);
                dp[i] = min(x1, x2);
            }

            return dp[n];
        }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {7, 4, 4 ,2, 6, 6 ,3, 4  };
    cout << ss.frogJump(8, vt) << endl;
    return 0;
}
