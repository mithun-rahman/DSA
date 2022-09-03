#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int maxProfit(vector<int>& prices, int fee) {

            int dp[3][3];
            memset(dp, 0, sizeof dp);

            for(int pos = prices.size(); pos >= 1; pos--) {
                for(int buy = 0; buy < 2; buy++) {
                    int x1, x2;
                    if(buy == 1) {
                        x1 = dp[(pos+1)%2][buy^1] - prices[pos-1];
                    }
                    else {
                        x1 = dp[(pos+1)%2][buy^1] + prices[pos-1] - fee;
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
    return 0;
}
