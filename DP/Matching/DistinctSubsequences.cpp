#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[1002][1002];
        int way(int pos1, int pos2, string s, string t)
        {
            if(pos2 == t.size()) {
                return 1;
            }
            if(pos1 == s.size()) {
                return 0;
            }
            if(dp[pos1][pos2] != -1) return dp[pos1][pos2];

            int x1, x2;
            x1 = x2 = 0;
            if(s[pos1] == t[pos2]) {
                x1 = way(pos1+1, pos2 + 1, s, t);
            }
            x2 = way(pos1+1, pos2, s, t);

            return dp[pos1][pos2] = x1 + x2;
        }

    public:

        int numDistinct(string s, string t) {

            memset(dp, -1, sizeof dp);
            int x = way(0, 0, s, t);
            for(int i = 0; i < s.size(); i++) {
                for(int j = 0; j <  t.size(); j++) {
                    printf("%4d", dp[i][j]);
                }
                cout << endl;
            }
            return x;
        }
};

int main()
{
    string s, t;
    s = "babgbag";
    t = "bag";
    Solution ss;
    cout << ss.numDistinct(s, t) << endl;
    return 0;
}
