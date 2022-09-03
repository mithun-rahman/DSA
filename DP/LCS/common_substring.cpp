#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[102][102];
        int cnt = 0;

        int commonSubstring(string A, string B)
        {
            int mx = 0;
            for(int i = 1; i <= A.size(); i++) {
                for(int j = 1; j <= B.size(); j++) {
                    if(A[i-1] == B[j-1]) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                    mx = max(mx, dp[i][j]);
                    printf("%4d", dp[i][j]);
                }
                cout << endl;
            }
            return mx;
        }

    public:

        void solve()
        {
            memset(dp, 0, sizeof dp);

            string A, B;
            int mx = -1;
            A = "tatb";
            B = "ttatb";

            cout << commonSubstring(A, B) << endl;

        }

};

int main()
{
    Solution ss;
    ss.solve();
    return 0;
}
