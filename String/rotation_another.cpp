#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        bool isRotation(string s1, string s2)
        {
            if(s1.size() != s2.size()) return 0;
            queue<char> q1, q2;

            for(int i = 0; i < s1.size(); i++) {
                q1.push(s1[i]);
            }
            for(int i = 0; i < s2.size(); i++) {
                q2.push(s2[i]);
            }

            for(int i = 0; i < s2.size(); i++) {
                if(q1 == q2) return 1;
                char ch = q2.front();
                q2.pop();
                q2.push(ch);
            }
            return 0;
        }
};

int main()
{
    string s1, s2;
    s1 = "ABCD";
    s2 = "CDAB";

    Solution ss;

    cout << ss.isRotation(s1, s2) << endl;
    return 0;
}
