#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
       int Lower(vector<int> &vt, int key)
       {
            int lo, hi, mid;
            lo = 0; hi = vt.size() - 1;

            if(key < vt[lo]) return -1;
            if(key > vt[hi]) return vt.size();

            while(hi > lo) {
                mid = (lo+hi+1)/2;
                if(key >= vt[mid]) {
                    lo = mid;
                }
                else hi = mid - 1;
            }
            return lo;
       }

    public:
        int KthMax(vector<int> &vt, int k)
        {
            int lo, hi, mid;
            lo = 1; hi = 1000;
            while(hi > lo) {
                mid = (lo + hi) / 2;
                if(Lower(vt, mid) >= k) {
                    hi = mid;
                }
                else lo = mid + 1;
            }
            return lo;
        }
};

int main()
{
    vector<int> vt ;
    vt = {1, 4, 4, 4, 17, 29, 30};
    Solution ss;
    cout << ss.KthMax(vt, 1) << endl;
    return 0;
}
