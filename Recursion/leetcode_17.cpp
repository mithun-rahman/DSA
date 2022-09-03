#include<bits/stdc++.h>

using namespace std;

vector<int> vt;
int n;

vector<string> keyboard, res;

void F(int pos, string st)
{
    if(pos == n) {
        string temp = "";
        for(int i = 0; i < n; i++) {
            int x = st[i] - 49;
            temp += keyboard[x][vt[i]];
        }
        res.push_back(temp);
        return ;
    }
    int d = st[pos] - 49;
    for(int i = 0; i < keyboard[d].size(); i++) {
        vt.push_back(i);
        F(pos+1, st);
        vt.pop_back();
    }
}

int main()
{
    keyboard.push_back("");
    keyboard.push_back("abc");
    keyboard.push_back("def");
    keyboard.push_back("ghi");
    keyboard.push_back("jkl");

    keyboard.push_back("mno");
    keyboard.push_back("pqrs");
    keyboard.push_back("tuv");
    keyboard.push_back("wxyz");

    string st;
    st = "49";
    n = st.size();
    F(0, st);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
