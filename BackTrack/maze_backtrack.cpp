#include<bits/stdc++.h>

using namespace std;

vector<char> vt;
bool visit[102][102];
int n;
int mat[102][102];

void Print(int i, int j, int pos)
{
    if(i + j == 2) {
        mat[i][j] = pos;
        for(int i = n; i >= 1; i--) {
            for(int j = n; j >= 1; j--) {
                printf("%d ", mat[i][j]);
            }
            cout << endl;
        }
        for(int i = 0; i < vt.size(); i++) {
            cout << vt[i] << "";
        }
        cout << endl;
        mat[i][j] = pos;
        return ;
    }
    if(visit[i][j]) return ;

    visit[i][j] = 1;

    if(i-1 >= 1) {
        vt.push_back('D');
        mat[i][j] = pos;
        Print(i-1, j, pos + 1);
        vt.pop_back();
        mat[i][j] = 0;
    }
    if(j - 1 >= 1) {
        vt.push_back('R');
        mat[i][j] = pos;
        Print(i, j-1, pos + 1);
        vt.pop_back();
        mat[i][j] = 0;
    }
    if(i+1 <= n) {
        vt.push_back('U');
        mat[i][j] = pos;
        Print(i + 1, j, pos + 1);
        vt.pop_back();
        mat[i][j] = 0;
    }
    if(j + 1 <= n) {
        vt.push_back('L');
        mat[i][j] = pos;
        Print(i, j+1, pos + 1);
        vt.pop_back();
        mat[i][j] = 0;
    }
    visit[i][j] = 0;
}

int main()
{
    n = 3;
    Print(n, n, 1);
    return 0;
}
