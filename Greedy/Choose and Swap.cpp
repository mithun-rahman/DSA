#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
    string chooseandswap(string s){

        int pos1, pos2;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            pos1 = pos2 = -1;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == ch) {
                    pos1 = i;
                    break;
                }
            }
            for(int i = 0; i < s.size(); i++) {
                if(s[i] > ch) {
                    pos2 = i;
                    break;
                }
            }
            if(pos1 > -1 && pos2 > -1 && pos1 > pos2) {
                char ch1, ch2;
                ch1 = s[pos1];
                ch2 = s[pos2];
                for(int i = 0;i < s.size(); i++) {
                    if(s[i] == ch1) {
                        s[i] = ch2;
                    }
                    else if(s[i] == ch2) {
                        s[i] = ch1;
                    }
                }
                return s;
            }
        }
        return s;
    }

};
int main()
{
    Solution ss;
    string s;
    s = "baab";
    cout << ss.chooseandswap(s) << endl;
    return 0;
}
