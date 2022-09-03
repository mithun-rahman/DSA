#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[303][303];

        int Fun(int i, int j, vector<int>& nums)
        {
            if(i > j) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            int mx = INT_MIN;
            for(int k = i; k <= j; k++) {
                int cost = Fun(i, k-1, nums) + Fun(k+1, j, nums) + nums[i-1]*nums[k]*nums[j+1];
                mx = max(mx, cost);
            }
            return dp[i][j] = mx;
        }
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();
            nums.push_back(1);
            nums.insert(nums.begin(), 1);

            memset(dp, -1, sizeof dp);
            int res = Fun(1, n, nums);

            memset(dp, 0, sizeof dp);

            for(int i = n; i >= 1; i--) {
                for(int j = i; j <= n; j++) {
                    int mx = INT_MIN;
                    for(int k = i; k <= j; k++) {
                        int cost = dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1];
                        mx = max(mx, cost);
                    }
                    dp[i][j] = mx;
                }
            }

            return dp[1][n];
        }
};
/*
burst reversely
*/
int main()
{
    Solution ss;
    vector<int> vt;
    vt = {3,1,5,8};
    cout << ss.maxCoins(vt) << endl;
    return 0;
}
