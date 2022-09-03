#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[30004][3];

        int Func(int pos, bool buy, vector<int>& prices)
        {
            if(pos == prices.size() + 1) {
                return 0;
            }

            if(dp[pos][buy] != -1) return dp[pos][buy];

            int x1, x2 ;
            x1 = x2 = 0;

            if(buy == 1) {
                x1 = Func(pos+1, buy^1, prices) - prices[pos-1];
            }
            else {
                x1 = Func(pos+1, buy^1, prices) + prices[pos-1];
            }
            x2 = Func(pos+1, buy, prices);
            return dp[pos][buy] = max(x1, x2);
        }
    public:
        int maxProfit(vector<int>& prices) {

            memset(dp, -1, sizeof dp);
            int x = Func(1, 1, prices);

            return x;
        }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {7,1,5,3,6,4};
    cout << ss.maxProfit(vt) << endl;
    return 0;
}
