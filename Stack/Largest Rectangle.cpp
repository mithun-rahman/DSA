#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<int> nearestSmall(vector<int> heights)
        {
            vector<int> vt;
            stack<int> st;
            for(int i=0; i < heights.size(); i++) {
                while(st.size() && heights[i] <= heights[st.top()]) {
                    st.pop();
                }
                if(st.size()) {
                    vt.push_back(i-st.top());
                }
                else {
                    vt.push_back(i+1);
                }
                st.push(i);
            }
            return vt;
        }
    public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> vt1 , vt2;
        vt1 = nearestSmall(heights);
        reverse(heights.begin(), heights.end());
        vt2 = nearestSmall(heights);

        int mx = 0;
        for(int i = 0; i < heights.size(); i++) {
            int v = (vt2[i] + vt1[heights.size()-i-1] -1)*heights[i];
            mx = max(mx, v);
        }
        return mx;

    }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {2, 1, 5, 6, 2, 3};
   ss.largestRectangleArea(vt) ;
    return 0;
}
