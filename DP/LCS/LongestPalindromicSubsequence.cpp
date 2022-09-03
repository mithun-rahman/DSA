#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[102][102];

        int F(int i, int j, string s)
        {
            if(i > j) return dp[i][j] = 0;
            if(i == j) return dp[i][j] = 1;
            if(dp[i][j] != -1) return dp[i][j];
            int x1, x2;
            x1 = x2 = 0;
            if(s[i] == s[j]) {
                x1 = 2 + F(i+1, j-1,s);
            }
            else {
                x1 = F(i+1, j, s);
                x2 = F(i, j-1, s);
            }
            return dp[i][j] = max(x1, x2);
        }

        int longestPalindromeSubsequence(string s)
        {
            for(int i = 0; i <= 100; i++) {
                for(int j = 0; j <= 100; j++) {
                    dp[i][j] = -1;
                }
            }
            int x = F(0, s.size()-1, s);

            for(int i = 0;i < s.size();i++) {
                for(int j = 0; j < s.size(); j++) {
                    if(dp[i][j] == -1) dp[i][j] = 0;
                    printf("%4d", dp[i][j]);
                }
                cout << endl;
            }
            return x;
        }
        public:
            void solve()
            {
                string s = "bbbaba";
                cout << longestPalindromeSubsequence(s) << endl;
            }
};

int main()
{
    Solution ss;
    ss.solve();

    return 0;
}
