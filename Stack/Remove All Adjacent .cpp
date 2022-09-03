#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> Fr;
        for(int i = 0; i < s.size(); i++) {
            if(st.size() == 0) {
                st.push(s[i]);
                Fr.push(1);
            }
            else {
                if(s[i] == st.top()) {
                    Fr.top() = Fr.top() + 1;
                }
                else {
                    st.push(s[i]);
                    Fr.push(1);
                }
            }
            if(Fr.size() && Fr.top() == k) {
                Fr.pop();
                st.pop();
            }
        }
        s = "";
        while(st.size()) {
            for(int i = 0; i < Fr.top(); i++) {
                s += st.top();
            }
            st.pop();
            Fr.pop();
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
        return s;
    }
};

int main()
{
    Solution ss;
    ss.removeDuplicates("pbbcggttciiippooaais", 2);
    return 0;
}
