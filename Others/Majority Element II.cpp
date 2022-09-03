#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

    vector<int> majorityElement(vector<int>& nums) {
        int val1, val2, cnt1, cnt2;
        val1 = val2 = -1;
        cnt1 = cnt2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(val1 == nums[i]) {
                cnt1++;
            }
            else if(val2 == nums[i]) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                val1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                val2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> vt;
        cnt1 = cnt2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val1) cnt1++;
            else if(nums[i] == val2) cnt2++;
        }
        if(cnt1 > nums.size()/3) vt.push_back(val1);
        if(cnt2 > nums.size()/3) vt.push_back(val2);
        return vt;
    }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {3, 2, 3};
    vt = ss.majorityElement(vt);
    for(int i = 0; i < vt.size(); i++) {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;
}
