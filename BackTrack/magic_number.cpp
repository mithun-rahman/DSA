#include<bits/stdc++.h>

using namespace std;

int main()
{
//    int n, fiv;
//    cin >> n;
//    int res = 0;
//    fiv = 5;
//    while(n) {
//        res += (n%2)*fiv;
//        n = n/2;
//        fiv = fiv * 5;
//    }
//    cout << res << endl;

    int sum = 0;
    for(int i = 0; i <= 15; i++) {
        sum = sum ^ i;
        cout << i <<" " << sum << endl;
    }
    return 0;
}
