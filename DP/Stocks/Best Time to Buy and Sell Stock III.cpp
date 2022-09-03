#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[30004][3][3];

        int Func(int pos, bool buy, int k, vector<int>& prices)
        {
            if(pos == prices.size() + 1) {
                return 0;
            }

            if(k == 2) return 0;

            if(dp[pos][buy][k] != -1) return dp[pos][buy][k];

            int x1, x2 ;
            x1 = x2 = 0;
 
            if(buy == 1) {
                x1 = Func(pos+1, buy^1, k, prices) - prices[pos-1];
            }
            else {
                x1 = Func(pos+1, buy^1, k+1, prices) + prices[pos-1];
            }
            x2 = Func(pos+1, buy, k, prices);

            return dp[pos][buy][k] = max(x1, x2);
        }
    public:
        int maxProfit(vector<int>& prices) {


            memset(dp, 0, sizeof dp);

            for(int pos = prices.size(); pos >= 1; pos--) {
                for(int buy = 0; buy < 2; buy++) {
                    for(int k = 0; k < 2; k++) {
                        int x1, x2;
                        if(buy == 1) {
                            x1 = dp[(pos+1)%2][buy^1][k] - prices[pos-1];
                        }
                        else {
                            x1 = dp[(pos+1)%2][buy^1][k+1] + prices[pos-1];
                        }
                        x2 = dp[(pos+1)%2][buy][k];

                        dp[pos%2][buy][k] = max(x1, x2);
                    }
                }
            }

            return dp[1][1][0];
        }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {3,3,5,0,0,3,1,4};
    cout << ss.maxProfit(vt) << endl;
    return 0;
}
