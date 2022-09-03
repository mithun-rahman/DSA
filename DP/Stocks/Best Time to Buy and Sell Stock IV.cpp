#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int dp[3][3][102];
        memset(dp, 0, sizeof dp);

        for(int pos = prices.size(); pos >= 1; pos--) {
                for(int buy = 0; buy < 2; buy++) {
                    for(int kk = 0; kk < k; kk++) {
                        int x1, x2;
                        if(buy == 1) {
                            x1 = dp[(pos+1)%2][buy^1][kk] - prices[pos-1];
                        }
                        else {
                            x1 = dp[(pos+1)%2][buy^1][kk+1] + prices[pos-1];
                        }
                        x2 = dp[(pos+1)%2][buy][kk];

                        dp[pos%2][buy][kk] = max(x1, x2);
                    }
                }
            }

            return dp[1][1][0];
    }
};

int main()
{
}
