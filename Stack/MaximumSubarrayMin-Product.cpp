#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        int mod = 1000000007;

        vector<int> nearestSmall(vector<int> nums)
        {
            vector<int> vt;
            stack<int> st;
            for(int i = 0;i < nums.size(); i++) {
                while(st.size() && nums[i] <= nums[st.top()]) {
                    st.pop();
                }
                if(st.size() == 0) vt.push_back(-1+2);
                else vt.push_back(st.top()+2);
                st.push(i);
            }
            return vt;
        }
    public:
        int maxSumMinProduct(vector<int>& nums) {
            vector<int> left, right;
            int n = nums.size();
            int prr[n+3];
            memset(prr, 0, sizeof prr);

            for(int i = 0; i < n; i++) prr[i+1] = (nums[i] + prr[i])%mod;

            left = nearestSmall(nums);
            reverse(nums.begin(), nums.end());
            right = nearestSmall(nums);

            reverse(right.begin(), right.end());
            reverse(nums.begin(), nums.end());

            int mx = 0;
            for(int i = 0; i < n; i++) {
                int r = n-right[i] +1 ;
                int l = left[i];
                int sum = (prr[r] - prr[l-1]) % mod;
                sum = (sum * nums[i]);
                mx =max(mx, sum);
            }
            return mx;
        }
};

int main()
{
    vector<int> vt;
    vt = {2, 3, 3, 1, 2};
    Solution ss;
    ss.maxSumMinProduct(vt);
    return 0;
}
