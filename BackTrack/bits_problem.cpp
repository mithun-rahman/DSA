#include<bits/stdc++.h>

using namespace std;

// check a bit

bool ChkBit(int mask, int k)
{
    return (mask >> k) & 1;
}

int setBit(int mask, int k)
{
    return mask | (1 << k);
}

int flipBit(int mask, int k)
{
    return mask ^ (1 << k);
}

int resetBit(int mask, int k)
{
    if(ChkBit(mask, k)) {
        return flipBit(mask, k);
    }
    return mask;
}

// bujhi ni
int rightMostsetbit(int n)
{
    return n & (~n);
}

int arr[102];
int bit[10];

int main()
{
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 8; j++) {
            bit[j] += ChkBit(arr[i], j);
        }
    }
    cin >> k;
    int num = 0;
    for(int i = 0; i < 8; i++) {
        cout << bit[i] << " ";
        num += (bit[i] % k)*(1<<i);
    }
    cout << endl;
    cout << num << endl;;
    return 0;
}
