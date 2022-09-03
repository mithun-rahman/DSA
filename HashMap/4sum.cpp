#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        void fourSum(vector<int> &nums, int target)
        {
            map <pair<int, int>, int> mp;

            for(int i = 0; i < nums.size(); i++)
            {
                for(int j = i+1; j < nums.size(); j++) {
                    mp[{i, j}] = nums[i]+nums[j];
                }
            }
            for(auto p:mp)
            {

            }
        }
};

int main()
{
    Solution s;
    return 0;
}
