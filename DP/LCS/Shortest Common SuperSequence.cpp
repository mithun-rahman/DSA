#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[102][102];
        int shortestCommon(string A, string B)
        {
            memset(dp, 0, sizeof dp);

            for(int i = 1;i <= A.size(); i++) {
                for(int j = 1; j <= B.size(); j++) {
                    int x1, x2 ;
                    x1 = x2 = 0;
                    if(A[i-1] == B[j-1]) {
                        x1 = 1 + dp[i-1][j-1];
                    }
                    else {
                        x1 = dp[i-1][j];
                        x2 = dp[i][j-1];
                    }
                    dp[i][j] = max(x1, x2);
                }
             }
             return A.size() + B.size() - dp[A.size()][B.size()];
        }

        void Print(string A, string B)
        {

            cout << A << " "<< B << endl;
            for(int i = 0; i <= A.size(); i++) {
                for(int j = 0;j <= B.size(); j++) {
                    printf("%4d", dp[i][j]);
                }
                cout << endl;
            }
            int i, j;
            i = A.size();
            j = B.size();
            string res = "";
            while(i > 0 && j > 0) {
                if(A[i-1] == B[j-1]) {
                    cout << A[i-1] << " ";
                    res += A[i-1];
                    i--;
                    j--;
                }
                else if(dp[i-1][j] > dp[i][j-1]) {
                    cout << A[i-1] << " ";
                    res += A[i-1];
                    i--;
                }
                else {
                    cout << B[j-1] <<" ";
                    res += B[j-1];
                    j--;
                }
            }
            while(i > 0) {
                res += A[i-1];
                cout << A[i-1] << " ";
                i--;
            }
            while(j > 0) {
                res += B[j-1];
                cout << B[j-1] << " ";
                j--;
            }
            cout << endl;
            reverse(res.begin(), res.end());
            cout << res << endl;
        }
    public:
        void solve()
        {
            string A, B;
            A = "eke";
            B = "geek";

            shortestCommon(A, B) ;
            Print(A, B);
        }
};

int main()
{
    Solution ss;
    ss.solve();
    return 0;
}
