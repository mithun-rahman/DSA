#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int matrix[102][102];
        int n, m;

        void input()
        {
            cin >> n >> m;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cin >> matrix[i][j];
                }
            }
        }

    public:

        int solve()
        {
            input();
            int sum = 0;
            for(int i = 0; i <= 100; i++) {
                matrix[i][0] = matrix[0][i] = 0;
            }

            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(matrix[i][j] == 0) continue;
                    int x = min(matrix[i-1][j], matrix[i][j-1]);
                    matrix[i][j] = 1 + min(x, matrix[i-1][j-1]);
                    sum += matrix[i][j];
                }
            }
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    printf("%4d", matrix[i][j]);
                }
                cout << endl;
            }
            return sum;
        }

};

int main()
{
    Solution ss;
    cout << ss.solve() << endl;
    return 0;
}
