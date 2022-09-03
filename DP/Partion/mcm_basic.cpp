#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[102][102];

    public:

        void mcm()
        {
            int n = 4;
            for(int i = n; i >= 1; i--) {
                for(int j = i; j <= n; j++) {
                    printf("(%d%2d)\n", i, j);
                    for(int k = i; k <= j; k++) {

                        printf("(%d, %d) (%d, %d)\n", i, k, k+1, j);
                    }
                }
                cout << endl;
            }
        }
};

int main()
{
    Solution ss;
    ss.mcm();
    return 0;
}
