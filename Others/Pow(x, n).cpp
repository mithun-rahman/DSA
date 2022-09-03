#include<bits/stdc++.h>

using namespace std;



int main()
{
    string s;
    cin >> s;
    int d = ss.findDiff(s);
    if(d < 0) d = -d;
    cout << d << endl;
    int depth = ss.maxDepth(s);
    return 0;
}
