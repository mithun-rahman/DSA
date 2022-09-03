#include<bits/stdc++.h>

using namespace std;

int arr[102];
int n;

int F(int pos)
{
    if(pos == n+1) return 1;

    return (arr[pos] >= arr[pos-1]) && F(pos+1);
}

int main()
{
    n = 4;
    arr[1] = 1; arr[2] = 4; arr[3] = 18; arr[4] = 17;
    cout << F(2) << endl;
    return 0;
}
