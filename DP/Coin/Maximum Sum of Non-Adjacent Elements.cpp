#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int dp[1003];

        int maxSum(int pos, vector<int> &nums)
        {
            if(pos > nums.size()) return 0;
            if(dp[pos] != -1) return dp[pos];
            int x1, x2;
            x1 = x2 = 0;
            x1 = maxSum(pos+2, nums) + nums[pos];
            x2 = maxSum(pos+1, nums);

            return dp[pos] = max(x1, x2);
        }
    public:
        int maximumNonAdjacentSum(vector<int> &nums){
            int even, odd;
            even = odd = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(i%2 ) {
                    odd += nums[i];
                    odd = max(odd, even);
                }
                else {
                    even += nums[i];
                    even = max(odd, even);
                }
            }
            return max(odd, even);
        }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {2, 1,4, 9};
    cout << ss.maximumNonAdjacentSum(vt) << endl;
    return 0;
}
