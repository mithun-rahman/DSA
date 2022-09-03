#include<bits/stdc++.h>

using namespace std;

vector<int> vt;

void F(int tar)
{
    if(tar == 0) {
        for(int i = 0; i < vt.size(); i++) {
            cout << vt[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= 6; i++) {
        if(tar - i >= 0) {
            vt.push_back(i);
            F(tar-i);
            vt.pop_back();
        }
    }
}

int main()
{
    F(4);
    return 0;
}
