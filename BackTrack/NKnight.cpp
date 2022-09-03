#include<bits/stdc++.h>

using namespace std;

bool visit[102][102];

int n;

void Print()
{
    for(int i  = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visit[i][j]) cout << "K " << " ";
            else cout << "X " << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(int row, int col)
{
    int fx[] = {-1, -1, -2, -2};
    int fy[] = {+2, -2, -1, +1};

    for(int i = 0; i < 4; i++) {
        int x = row + fx[i];
        int y = col + fy[i];

        if((x >= 1 && x <= n) && (y >= 1 && y <= n)) {
            if(visit[x][y]) return 0;
        }
    }
    return 1;
}

void NKnight(int row, int col, int kn)
{
    if(kn == 0) {
        Print();
        return ;
    }

    if(row == n  && col == n+1) return;

    if(col == n + 1) {
        NKnight(row+1, 1, kn);
        return ;
    }

    if(isValid(row, col)) {
        visit[row][col] = 1;
        NKnight(row, col+1, kn-1);
        visit[row][col] = 0;
    }

    NKnight(row, col + 1, kn);
}

int main()
{
    n = 4;
    NKnight(1, 1, n);
    return 0;
}
