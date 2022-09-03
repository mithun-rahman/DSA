#include<bits/stdc++.h>

using namespace std;

/// Offline Hash Technique

class Solution
{
    int longestConsecutive(vector<int>& nums) {
        int mx, cnt, x;
        mx = 0;
        unordered_map<int, bool> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]-1) == mp.end()) {
                x = nums[i];
                cnt = 0;
                while(mp.find(x) != mp.end()) {
                    cnt++;
                    x++;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};

int main()
{

    return 0;
}
