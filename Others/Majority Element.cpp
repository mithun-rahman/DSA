#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val, cnt;
        cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                val = nums[i];
            }
            if(nums[i] == val) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return val;
    }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {2,2,1,1,1,2,2};
    cout << ss.majorityElement(vt) << endl;

    return 0;
}
