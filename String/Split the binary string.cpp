#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        int numSplit(string s)
        {
            int zr, on, cnt;
            zr = on = cnt = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '0') {
                    zr++;
                }
                else {
                    on++;
                }
                if(zr == on) {
                    cnt++;
                }
            }
            if(zr != on) cnt = -1;

            return cnt;
        }
};

int main()
{
    Solution ss;
    string s = "0100110101";
    cout << ss.numSplit(s) << endl;
    return 0;
}
