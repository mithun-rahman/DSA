#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[102][102];

        int mcm(int i, int j, vector<int> &arr)
        {
            if(i == j) {
                return 0;
            }

            if(dp[i][j] != -1) return dp[i][j];

            int x = INT_MAX;

            for(int k = i; k < j; k++) {
                int steps = mcm(i, k, arr) + mcm(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
                x = min(x, steps);
            }

            return dp[i][j] = x;
        }
    public:
        int matrixMultiplication(vector<int> &arr, int N)
        {
            memset(dp, 0, sizeof dp);

            for(int i = N-1; i >= 1; i--) {
                for(int j = i+1; j < N; j++) {
                    int x = INT_MAX;
                    for(int k = i; k < j; k++) {
                        int steps = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                        x = min(x, steps);
                    }
                    dp[i][j] = x;
                }
            }

            return dp[1][N-1];
        }
};

int main()
{
//    vector<int> vt;
//    vt = {4, 5, 3 ,2};
//    Solution ss;
//    cout << ss.matrixMultiplication(vt, 4) << endl;

    int n = 4;
    for(int i = n; i >= 1; i--) {
        for(int j = i+1; j <= n; j++) {
            cout << "( " << i << " "<< j << " ) "<< endl;
            for(int k = i; k < j; k++) {
                cout << i << " "<< k <<" | "<< k+1 <<" "<< j<< endl;
            }
        }
    }
    return 0;
}
