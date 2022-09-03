#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int split(vector<int> &vt, int k)
        {
            int sum, cnt;
            sum = cnt = 0;
            for(int i = 0; i < vt.size(); i++) {
                if(vt[i] > k) {
                    cnt = vt.size() + 2;
                    break;
                }
                else if(sum + vt[i] > k) {
                    cnt++;
                    sum = vt[i];
                }
                else {
                    sum = sum + vt[i];
                }
            }
            return cnt + 1;
        }
    public:
        int splitArray(vector<int>& nums, int m) {
            if(m > nums.size() ) return 0;

            int lo, hi, mid;
            lo = hi = 0;
            for(int i = 0; i < nums.size(); i++) {
                hi += nums[i];
            }
            while(hi > lo) {
                mid = (lo + hi) / 2;
                if(split(nums, mid) <= m) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            return lo;
        }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {1, 4, 4};
    int m = 3;
    cout << ss.splitArray(vt, m) << endl;
    return 0;
}
