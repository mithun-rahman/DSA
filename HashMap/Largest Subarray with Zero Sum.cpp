#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int maxLen(vector<int>&A, int n)
        {
            int sum, prev, mx;
            prev = mx = 0;
            unordered_map<int, int> mp;
            mp[0] = 0;
            for(int i = 1; i <= n; i++) {
                sum = prev + A[i-1];
                if(mp.find(sum) != mp.end()) {
                    mx = max(mx, i - mp[sum]);
                }
                if(mp.find(sum) == mp.end()) {
                    mp[sum] = i;
                }
                prev = sum;
            }
            return mx;
        }
};

int main()
{
    vector<int> vt;
    vt.push_back(15);
    vt.push_back(-2);
    vt.push_back(2);
    vt.push_back(-8);

    vt.push_back(1);
    vt.push_back(7);
    vt.push_back(10);
    vt.push_back(23);

    Solution ss;
    cout << ss.maxLen(vt, 8) << endl;
    return 0;
}
