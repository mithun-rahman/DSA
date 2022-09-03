#include<bits/stdc++.h>

using namespace std;

void Print(vector<int> vt)
{
    for(int i = 0; i < vt.size(); i++) {
        cout <<vt[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> Final, temp;
    vector<int> vt;
    Final.push_back(vt);

    int n = 3;
    for(int i = 1; i <= n; i++) {
        temp = Final;
        for(int j = 0; j < temp.size(); j++) {
            temp[j].push_back(i);
            Final.push_back(temp[j]);
        }
    }
    for(int i = 0; i < Final.size(); i++) {
        Print(Final[i]);
    }
    return 0;
}
