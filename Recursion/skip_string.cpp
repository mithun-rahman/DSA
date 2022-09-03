#include<bits/stdc++.h>

using namespace std;

string F(int pos, string st, string apple, string app, string ans)
{
    if(pos == st.size()) return ans;

    string temp = "";
    for(int i = pos; i < st.size(); i++) {
        temp += st[i];
        if(temp.size() == apple.size()) break;
    }

    if(temp == apple) {
        return F(pos + temp.size(), st, apple, app, ans + apple) ;
    }
    else {
        temp = "";
        for(int i = pos; i < st.size(); i++) {
            temp += st[i];
            if(temp.size() == app.size()) break;
        }
        if(app == temp) {
            return F(pos+app.size(), st, apple, app, ans);
        }
        else return  F(pos+1, st, apple, app, ans + st[pos]);
    }
}

int main()
{
    cout << F(0, "ttapplexyappyz", "apple", "app", "") << endl;
    return 0;
}
