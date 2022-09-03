#include<bits/stdc++.h>

using namespace std;

int r, c;

void Print(int i, int j)
{
    if(i == 0) return ;

    if(j <= i) {
        cout << "*";
        Print(i, j + 1);
    }
    else {
        cout << endl;
        Print(i-1, 1);
    }
}

int main()
{
    r = c = 4;
    Print(4, 1);
    return 0;
}
