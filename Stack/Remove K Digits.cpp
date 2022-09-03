#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        string removeKdigits(string num, int k) {
            stack<char> st;
            for(int i = 0; i < num.size(); i++) {
                if(k) {
                    while(st.size() && num[i] < st.top()) {
                        st.pop();
                        k--;
                        if(k == 0) break;
                    }
                    st.push(num[i]);
                }
                else {
                    st.push(num[i]);
                }
            }
            while(k) {
                st.pop();
                k--;
            }
            num.clear();

            while(st.size()) {
                num += st.top();
                st.pop();
            }

            if(num.size()) {
                int i = num.size()-1;
                while(num[i] == '0') {
                    num.pop_back();
                    i--;
                }
                if(num.size()) reverse(num.begin(), num.end());
                else num = "0";
            }
            else num = "0";
            return num;
        }
};

int main()
{
    Solution ss;
    cout << ss.removeKdigits("10", 2) << endl;

    return 0;
}
