#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<string> parlist;
        void generat(int open, int close, int n, string s)
        {
            if(open + close == n+n) {
                parlist.push_back(s);
                return ;
            }
            else if(open == close) {
                generat(open+1, close, n, s + '(');
            }
            else if(open == n) {
                generat(open, close+1, n, s+')');
            }
            else if(open > close) {
                generat(open + 1, close, n, s+'(');
                generat(open, close+1, n, s+')');
            }
        }
    public:
    vector<string> generateParenthesis(int n) {
        generat(0, 0, n, "");
        for(int i = 0; i < parlist.size(); i++) {
            cout << parlist[i] << " ";
        }
        return parlist;
    }
};

int main()
{
    Solution ss;
    ss.generateParenthesis(3);
    return 0;
}
