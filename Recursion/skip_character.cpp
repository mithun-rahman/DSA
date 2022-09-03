#include<bits/stdc++.h>

using namespace std;

string F(string st, int pos, string temp)
{
    if(pos == st.size()) {
        return temp;
    }

    if(st[pos] == 'a') return F(st, pos+1, temp);
    else return F(st, pos+1, temp + st[pos]);
}

string FF(string st, int pos)
{
    if(pos == st.size()) return "";

    if(st[pos] == 'a') return FF(st, pos+1);
    else return st[pos] + FF(st, pos+1) ;
}

int main()
{
    string st;
    cin >> st;
    cout << F(st, 0, "") << endl;
    cout << FF(st, 0) << endl;
    return 0;
}
