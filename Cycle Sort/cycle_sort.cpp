#include<bits/stdc++.h>

using namespace std;
/*
4
3 1 2 4
*/

int main()
{
    vector<int> arr;
    int n, v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v;
        arr.push_back(v);
    }

    for(int i = 1; i <= n; i++) {

        while(arr[i-1] != i) {
            if(arr[i-1] == arr[arr[i-1]-1]) {
                cout << arr[i-1] << endl;
                arr[i-1] = arr[arr[i-1]-1] = 1000;
                break;
            }
            if(arr[i-1] == 1000) break;
            swap(arr[i-1], arr[arr[i-1]-1]);
        }
    }

    return 0;
}
