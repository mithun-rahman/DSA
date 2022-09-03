#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        bool isPalindrome(string s, int lo, int hi)
        {
            string xx, yy;
            xx="";
            for(int i = lo; i <= hi; i++) {
                xx += s[i];
            }
            yy = xx;
            reverse(xx.begin(), xx.end());
            return xx == yy;
        }
    public:
        void solve(string s)
        {
            int dp[102][102];
            memset(dp, 0, sizeof dp);
            int n = s.size();

            for(int i = n; i >= 1; i--) {
                for(int j = i+1; j <= n; j++) {

                    dp[i][j] = 100000;

                    if(isPalindrome(s, i-1, j-1)) {
                        dp[i][j] = 0;
                    }

                    for(int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                    }
                }
            }
            cout << dp[1][n] << endl;
        }
};

int main()
{
    Solution ss;
    string s = "NITIN";
    ss.solve(s);
    return 0;
}
