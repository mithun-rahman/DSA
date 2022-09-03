#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[5003][3];

        int Func(int pos, bool buy, vector<int>& prices)
        {
            if(pos > prices.size()) {
                return 0;
            }

            if(dp[pos][buy] != -1) return dp[pos][buy];

            int x1, x2 ;
            x1 = x2 = 0;

            if(buy == 1) {
                x1 = Func(pos+1, buy^1, prices) - prices[pos-1];
            }
            else {
                x1 = Func(pos+2, buy^1, prices) + prices[pos-1];
            }
            x2 = Func(pos+1, buy, prices);

            return dp[pos][buy] = max(x1, x2);
        }
    public:
        int maxProfit(vector<int>& prices) {

            memset(dp, 0, sizeof dp);

            for(int pos = prices.size(); pos >= 1; pos--) {
                for(int buy = 0; buy < 2; buy++) {
                    int x1, x2;
                    if(buy == 1) {
                        x1 = dp[(pos+1)%2][buy^1] - prices[pos-1];
                    }
                    else {
                        x1 = dp[(pos+2)%2][buy^1] + prices[pos-1];
                    }
                    x2 = dp[(pos+1)%2][buy];

                    dp[pos%2][buy] = max(x1, x2);
                }
            }
            return dp[1][1];
        }
};


int main()
{
    Solution ss;
    vector<int> vt;
    vt = {1,2,3,0,2};
    cout << ss.maxProfit(vt) << endl;
    return 0;
}
