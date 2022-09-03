#include<bits/stdc++.h>

using namespace std;

int per[103];
int num[102];
int n;

void F(int pos)
{
    if(pos == n + 1) {
        for(int i = 1; i <= n; i++) {
            cout << per[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(num[i] == 0) {
            per[pos] = i;
            num[i] = 1;
            F(pos+1);
            num[i] = 0;
        }
    }
}

int main()
{
    n = 3;
    F(1);
    return 0;
}
