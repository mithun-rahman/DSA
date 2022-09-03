#include<bits/stdc++.h>

using namespace std;

int n;
bool visit[102][103];

void Print()
{
    for(int i  = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visit[i][j]) cout << "Q " << " ";
            else cout << "X " << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(int row, int col)
{
    for(int i = row; i >= 1; i--) {
        if(visit[i][col]) {
            //cout << "Row" << endl;
            return 0;
        }
    }
    for(int i = 0; i < min(col, row); i++) {
        if(visit[row - i][col - i]) {
          //  cout <<"Left" << endl;
            return 0;
        }
    }
    for(int i = 0; i < min(n-col+1, row); i++) {
        if(visit[row - i][col + i]) {
            //cout << "Right" << endl;
            return 0;
        }
    }
    return 1;
}

int NQueen(int row)
{
    if(row == n + 1) {
        //Print();
        return 1;
    }

    int cnt = 0;
    for(int col = 1; col <= n; col++) {
       // cout << row << ", " << col <<" " << isValid(row, col) << endl;
        if(isValid(row, col)) {
            visit[row][col] = 1;
            cnt += NQueen(row + 1);
            visit[row][col] = 0;
        }
    }
    return cnt;
}

int main()
{
    n = 5;
    cout << NQueen(1) << endl;
    return 0;
}
