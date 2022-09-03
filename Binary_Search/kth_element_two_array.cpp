#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:

        double KthMax(vector<int>&arr1, vector<int>&arr2, int n, int m, int k)
        {
            if(n > m) {
                return KthMax(arr2, arr1, m, n, k);
            }
            int lo, hi, mid, t, L1, L2, R1, R2, INF;
            INF = 100000000;
            lo = max(0, k-m); hi = min(k, n);
            while(lo <= hi) {
                mid = (lo+hi)/2;
                t = k - mid;
                L1 = mid == 0 ? -INF:arr1[mid-1];
                L2 = t == 0 ? -INF:arr2[t-1];
                R1 = mid == n ? INF:arr1[mid];
                R2 = t == m ? INF:arr2[t];

                if(L1 <= R2 && L2 <= R1) {
                    double x;
                    x = max(L1, L2);

                    if((n+m)%2==0) {

                        x = max(L1, L2) + min(R1, R2);
                        return x / 2;
                    }
                    return x;
                }
                if(L1 > R2) hi = mid - 1;
                else lo = mid + 1;
            }

        }
};

int main()
{
    vector<int> vt1, vt2;
    vt1 = {1, 3};
    vt2 = {2, 3};
    int n, m, k;
    n = 2; m = 2;
    k = (n+m+1)/2;
    Solution ss;
    cout << ss.KthMax(vt1, vt2, n, m, k) << endl;


    return 0;
}
