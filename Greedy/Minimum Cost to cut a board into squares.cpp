#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[103];
    arr[0] = 2; arr[1] = 6; arr[2] = 1; arr[3] = 9;
    arr[4] = 4; arr[5] = 5; arr[6] = 3;
    int N = 7;
    unordered_map<int, bool> mp;
    for(int i = 0; i < N; i++) {
      mp[arr[i]] = 1;
    }
    int mx = 0;
    for(int i = 0;i < N; i++) {
      if(mp.find(arr[i] - 1) == mp.end()) {
          int cnt = 0;
          int x = i;
          while(mp.find(arr[x]) != mp.end()) {
              x++;
              cnt++;
          }
          mx = max(mx, cnt);
      }
    }
    cout << mx << endl;
    return 0;
}
