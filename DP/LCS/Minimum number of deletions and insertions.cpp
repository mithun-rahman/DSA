#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        public:
	int minOperations(string str1, string str2)
	{
	    int dp[1002][1002];
        memset(dp, 0, sizeof dp);

        for(int i = 1;i <= str1.size(); i++) {
            for(int j = 1; j <= str2.size(); j++) {
                int x1, x2 ;
                x1 = x2 = 0;
                if(str1[i-1] == str2[j-1]) {
                    x1 = 1 + dp[i-1][j-1];
                }
                else {
                    x1 = dp[i-1][j];
                    x2 = dp[i][j-1];
                }
                dp[i][j] = max(x1, x2);
            }
         }
         return str1.size() + str2.size() - 2*dp[str1.size()][str2.size()];

	}
    public:
        void solve()
        {
            string A, B;
            A = "geek";
            B = "eke";

            cout << minOperations(A, B) << endl;
        }
};

int main()
{
    Solution ss;
    ss.solve();
    return 0;
}
