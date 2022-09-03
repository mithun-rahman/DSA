#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
       stack<string> st;
       cout << path << endl;

        string s = "";
        for(int i= 0;i < path.size(); i++) {
            if(path[i] == '/') {
                  if(s.size()) {
                    cout << s << endl;
                      reverse(s.begin(), s.end());
                      if(s == ".." ) {
                          if(st.size()) st.pop();
                      }
                      else if(s == ".") ;
                      else st.push(s);

                      s = "";
                  }
             }
             else s += path[i];
        }
        if(s.size()) {
              reverse(s.begin(), s.end());
              if(s == ".." ) {
                  if(st.size()) st.pop();
              }
              else if(s == ".") ;
              else st.push(s);
        }
        s = "";
        while(st.size()) {
            s += st.top();
            s += "/";
            st.pop();
        }
        reverse(s.begin(), s.end());
        if(s == "") s = "/";
        return s;

    }
};

int main()
{
    Solution ss;
    cout << ss.simplifyPath("/a//b////c/d//././/..");
    return 0;
}
