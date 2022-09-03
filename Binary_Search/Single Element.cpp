#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {

            int n = nums.size();

            if(n == 1) return nums[0];
            if(nums[0] != nums[1]) return nums[0];
            if(nums[n-1] != nums[n-2]) return nums[n-1];

            int lo, hi, mid, f, s;
            lo = 1; hi = n-2;
            while(hi >= lo) {
                cout << lo << " " << hi << endl;
                mid = (lo+hi)/2;
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {

                    break;
                }
                if(nums[mid] == nums[mid-1]) {
                    f = mid - 1;  s = mid;
                }
                else {
                    f = mid; s = mid + 1;
                }
                if(f%2 == 1 && s % 2 == 0) {
                    hi = f-1;
                }
                else {
                    lo = s + 1;
                }
            }


            return nums[mid];
        }
};

int main()
{
    vector<int> vt;
    vt = {1,1,2,3,3,4,4,8,8};
    Solution ss;
    cout << ss.singleNonDuplicate(vt) << endl;
    return 0;
}
