#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int right = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(right > nums[i]) return 1;
            while(st.size() && st.top() < nums[i]) {
                right = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return 0;
    }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {1,2,3,4};
    cout << ss.find132pattern(vt) << endl;
    return 0;
}
