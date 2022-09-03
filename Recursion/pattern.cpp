#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r, u, d, mn;
    n = 2;
    for(int i = 1; i <= 2*n+1; i++) {
        for(int j = 1; j <= 2*n+1; j++) {
            l = j;   r = 2*n+2-j; mn = min(l, r);
            u = i;   d = 2*n+2-i; mn = min(mn, u);
            mn = min(mn, d);
            cout << n - mn + 2<< " ";
        }
        cout << endl;
    }
    return 0;
}
