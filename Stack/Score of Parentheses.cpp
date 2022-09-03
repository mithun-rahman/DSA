#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int ed[51];
    public:
        int score(int b, int e)
        {
            if(b+1 == e) return 1;
            int mid, x1, x2;
            mid = ed[b];
            x1 = x2 = 0;
            if(mid == e) {
                x1 = 2*score(b+1, e-1);
            }
            else {
                x1 = score(b, mid);
                x2 = score(mid+1, e);
            }
            return x1 + x2;
        }
        int scoreOfParentheses(string s)
        {
            memset(ed, -1, sizeof ed);
            stack<int> st;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '(') {
                    st.push(i);
                }
                else {
                    ed[st.top()] = i;
                    st.pop();
                }
            }

            return score(0, s.size()-1);
        }
};

int main()
{
    Solution ss;
    cout << ss.scoreOfParentheses("((())())") <<endl;
    return 0;
}
