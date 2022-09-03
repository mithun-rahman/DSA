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
    vector<vector<int>> Final, temp, prev;
    vector<int> vt;
    temp.push_back(vt);
    Final.insert(Final.end(), temp.begin(), temp.end());
    prev = temp;

    int n = 4;
    int arr[10];
    arr[1] = 1; arr[2] = 2; arr[3] = 2, arr[4] = 2;
    for(int i = 1; i <= n; i++) {
        if(arr[i] != arr[i-1]) {
            temp = Final;
        }
        else {
            temp = prev;
        }
        for(int j = 0; j < temp.size(); j++) {
            temp[j].push_back(arr[i]);
        }
        Final.insert(Final.end(), temp.begin(), temp.end());
        prev = temp;
    }
    for(int i = 0; i < Final.size(); i++) {
        Print(Final[i]);
    }
    return 0;
}
