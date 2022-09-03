#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[1003][1003];

        int Fun(int i, int j, vector<int> &cuts)
        {
            if(i > j) {
                return 0;
            }
            if(dp[i][j] != -1) return dp[i][j];

            int mn = INT_MAX;
            for(int k = i; k <= j; k++) {
                int cost = Fun(i, k-1, cuts) + Fun(k+1, j, cuts) + cuts[j+1] - cuts[i-1];
                mn = min(mn, cost);
            }
            return dp[i][j] = mn;
        }
    public:
        int cost(int n, int c, vector<int> &cuts){

            cuts.push_back(n);
            cuts.insert(cuts.begin(), 0);

            sort(cuts.begin(), cuts.end());
            memset(dp, -1, sizeof dp);

            int x = Fun(1, c, cuts);

            memset(dp, 0, sizeof dp);

            for(int i = c; i >= 1; i--) {
                for(int j = i; j <= c; j++) {
                    int mn = INT_MAX;
                    for(int k = i; k <= j; k++) {
                        int cost = dp[i][k-1] + dp[k+1][j] + cuts[j+1]-cuts[i-1];
                        mn = min(mn, cost);
                    }
                    dp[i][j] = mn;
                }
            }

            return dp[1][c];
        }
};

int main()
{
    vector<int> vt;
    vt = {1};
    return 0;
}
