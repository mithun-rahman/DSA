#include<bits/stdc++.h>

using namespace std;

class Sort
{
    public:
        int arr[103];

        void bubble(int n)
        {
            for(int i = 1; i <= n; i++) {
                for(int j = i+1; j <= n; j++) {
                    if(arr[j-1] > arr[j]) {
                        swap(arr[j-1], arr[j]);
                    }
                }
            }
            for(int i = 1; i <= n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void selection(int n)
        {
            for(int i = 1; i <= n; i++) {
                for(int j = i+1; j <= n; j++) {
                    if(arr[i] > arr[j]) {
                        swap(arr[i], arr[j]);
                    }
                }
            }
            for(int i = 1; i <= n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Sort bb;
    for(int i = 5; i >= 1; i--) {
        bb.arr[i] = i;
    }
    bb.bubble(5);
    bb.selection(5);
    return 0;
}
