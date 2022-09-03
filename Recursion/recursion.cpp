#include<bits/stdc++.h>

using namespace std;

class Recursion
{
    private:
        int arr[100];
        int way(int n)
        {
            if(n == 0) return 1;

            int x = 0;
            for(int i = 0;i < 2; i++) {
                if(n - arr[i] >= 0) {
                    x += way(n - arr[i]);
                }
            }
            return x;
        }
        void allsubsequence(int pos, int sum, vector<int> &vt)
        {
            if(sum == 0) {
                for(int i = 0; i < vt.size(); i++) {
                    cout << vt[i] << " ";
                }
                cout << endl;
                return ;
            }
            if(pos == -1) {
                return ;
            }
            allsubsequence(pos-1, sum, vt);
            vt.push_back(arr[pos]);
            allsubsequence(pos-1, sum-arr[pos], vt);
            vt.pop_back();
        }
    public:
        void solve()
        {
            arr[0] = 1; arr[1] = 2, arr[2] = 3;
            vector<int> vt;
            allsubsequence(2, 3, vt);
        }
};

int main()
{
    Recursion rc;
    rc.solve();
    return 0;
}
