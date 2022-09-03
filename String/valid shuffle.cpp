#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        bool isSuffle(string s, string s1, string s2)
        {
            int l, l1, l2, i, j, pos;
            i = j = pos = 0;
            l1 = s1.size();
            l2 = s2.size();
            l = s.size();

            if(l1 + l2 != l) return 0;

            while(pos < l) {
                if(s[pos] == s1[i]) {
                    i++;
                }
                else if(s[pos] == s2[j]) {
                    j++;
                }
                pos++;
            }
            if(i < l1) return 0;
            if(j < l2) return 0;

            return 1;
        }
};

int main()
{
    Solution ss;
    string s = "x1y2";
    string s1, s2;
    s1 = "xy";
    s2 = "12";

    cout << ss.isSuffle(s, s1, s2) << endl;
    return 0;
}
