#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[102][102];

        int LCS(string A, string B)
        {
            memset(dp, 0, sizeof dp);

            for(int i = 1;i <= A.size(); i++) {
                for(int j = 1; j <= B.size(); j++) {
                    int x1, x2;
                    x1 = x2 = 0;
                    if(A[i-1] == B[j-1]) {
                        x1 = dp[i-1][j-1] + 1;
                    }
                    else {
                        x1 = dp[i-1][j];
                        x2 = dp[i][j-1];
                    }
                    dp[i][j] = max(x1, x2);
                }
            }
            return dp[A.size()][B.size()];
        }

        void Print(int i, int j, string A, string B, string res)
        {
            if(i == 0 || j == 0) {
               // reverse(res.begin(), res.end());
                cout << res << endl;
                return ;
            }

            if(A[i-1] == B[j-1]) {
                res += A[i-1];
                Print(i-1, j-1, A, B, res);
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    Print(i-1, j, A, B, res);
                }
                else if(dp[i][j-1] > dp[i-1][j]) {
                    Print(i, j-1, A, B, res);
                }
                else {
                    Print(i-1, j, A, B, res);
                    Print(i, j-1, A, B, res);
                }
            }
        }

        void smallestLCS(int i, int j, int len, string A, string B, string res)
        {
            if(len == 0) {
                cout << res << endl;
                return ;
            }

            for(char ch = 'a'; ch <= 'z'; ch++) {
                int a, b;
                a = b = -1;
                for(int k = i; k >= 1; k--) {
                    if(ch == A[k-1]) {
                        a = k;
                        break;
                    }
                }
                for(int k = i; k >= 1; k--) {
                    if(ch == B[k-1]) {
                        b = k;
                        break;
                    }
                }
                if(a > -1 && b > -1) {
                    res += ch;
                    smallestLCS(a-1,  b-1,len-1, A, B, res);
                    break;
                }
            }
        }

        void distinctLCS(int i, int j, int ln, string A, string B, string res)
        {
            if(ln == 0) {
                cout << res << endl;
                return ;
            }

            for(char ch = 'a'; ch <= 'z'; ch++) {
                int a, b;
                a = b = -1;
                for(int k = i; k >= 1; k--) {
                    if(ch == A[k-1]) {
                        a = k;
                        break;
                    }
                }
                for(int k = i; k >= 1; k--) {
                    if(ch == B[k-1]) {
                        b = k;
                        break;
                    }
                }
                if(a > -1 && b > -1) {
                    distinctLCS(a-1, b-1, ln - 1, A, B, res + ch);
                }
            }
        }

    public:
        void solve()
        {
            string A, B;
            A = "abcd";
            B = "cdab";

            reverse(A.begin(), A.end());
            reverse(B.begin(), B.end());

            int ln = LCS(A, B);

            for(int i = 1; i <= A.size(); i++) {
                for(int j = 1; j <= B.size(); j++) {
                    printf("%4d", dp[i][j]);
                }
                cout << endl;
            }

           // Print(A.size(), B.size(), A, B, "");

           // smallestLCS(A.size(), B.size(), ln, A, B, "");

           distinctLCS(A.size(), B.size(), ln, A, B, "");
        }
};

int main()
{
    Solution ss;
    ss.solve();
    return 0;
}
