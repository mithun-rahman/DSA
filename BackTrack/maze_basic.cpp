#include<bits/stdc++.h>

using namespace std;


// Numbers of ways

int F(int i, int j)
{
    if(i == 1 || j == 1) return 1;

    return F(i-1, j) + F(i, j-1);
}

int mat[102][102];

// Printing Path

vector<char> vt;

void Path(int i, int j)
{
    if(i == 1 && j == 1)
    {
        for(int i = 0; i < vt.size(); i++) {
            cout << vt[i] << "";
        }
        cout << endl;
    }
    if(i - 1 >= 1) {
        vt.push_back('D');
        Path(i-1, j);
        vt.pop_back();
    }
    if(j - 1 >= 1) {
        vt.push_back('R');
        Path(i, j-1);
        vt.pop_back();
    }
}
//if Diagonal allowed

vector<char> vd;
void PrintAll(int i, int j)
{
    if(i + j == 2)
    {
        for(int i = 0; i < vd.size(); i++) {
            cout << vd[i] << "";
        }
        cout << endl;
        return;
    }
    if(i - 1 >= 1 && j >= 1) {
        vd.push_back('D');
        PrintAll(i-1, j-1);
        vd.pop_back();
    }
    if(i - 1 >= 1) {
        vd.push_back('V');
        PrintAll(i-1, j);
        vd.pop_back();
    }
    if(j - 1 >= 1) {
        vd.push_back('H');
        PrintAll(i, j-1);
        vd.pop_back();
    }
}
bool restrict[102][102];
vector<char> vr;
void PrintObstacle(int i, int j)
{
    if(restrict[i][j]) return;
    if(i == 1 && j == 1)
    {
        for(int i = 0; i < vr.size(); i++) {
            cout << vr[i] << "";
        }
        cout << endl;
    }
    if(i - 1 >= 1) {
        vr.push_back('D');
        PrintObstacle(i-1, j);
        vr.pop_back();
    }
    if(j - 1 >= 1) {
        vr.push_back('R');
        PrintObstacle(i, j-1);
        vr.pop_back();
    }
}

int main()
{
    int n;
    n = 3;
//   // cout << F(n, n) << endl;
//     Path(n, n);
//    PrintAll(n, n);

    restrict[2][2] = 1;
    PrintObstacle(n, n);
    return 0;
}
