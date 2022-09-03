#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
        int zr[2002];
        bool dp[2002][2002];

    public:
        bool isMatch(string s, string p) {

            int n, m;
            n = s.size();
            m = p.size();
            zr[0] = 0;
            for(int i = 1; i <=m; i++) {
                if(p[i-1] == '*') zr[i] = 1;
            }
            for(int i = 1; i <= m; i++) {
                zr[i] += zr[i-1];
            }

            memset(dp, 0, sizeof dp);

            dp[n+1][m+1] = 1;

            for(int i = 1;i <= m; i++) {
                dp[n+1][i] = (zr[m]-zr[i-1]) == (m - i + 1);
            }

            for(int pos1 = n; pos1 >= 1; pos1--) {
                for(int pos2 = m; pos2 >= 1; pos2--) {
                    bool x = 0;
                    if(s[pos1-1] == p[pos2-1] || p[pos2-1] == '?') {
                        x = dp[pos1+1][pos2+1];
                    }
                    else if(p[pos2-1] == '*') {
                        x = dp[pos1+1][pos2] | dp[pos1][pos2+1];
                    }
                    dp[pos1][pos2] = x;
                }
            }


            return dp[1][1];
        }
};

int main()
{
    Solution ss;

    return 0;
}
