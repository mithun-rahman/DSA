#include<bits/stdc++.h>

using namespace std;

class QuickSort
{
    private:
        int arr[102];

        void negativeLeft(int lo, int hi)
        {
            int pivot, s, e;
            pivot = 0;
            s = lo;
            e = hi;
            int cnt = 0;
            while(s <= e) {
                while(arr[s] < pivot) {
                    s++;
                }
                while(arr[e] > pivot) {
                    e--;
                    cnt++;
                }
                if(s <= e) {
                    swap(arr[s], arr[e]) ;
                    s++;
                    e--;
                }
            }
            for(int i = lo; i <= hi; i++) {
                cout << arr[i] <<" ";
            }
            cout << endl;
        }

    public:
        void init()
        {
            arr[1] = 3; arr[2]= -2; arr[3]= 5; arr[4]=-4; arr[5]=16;
            negativeLeft(1, 5);
        }
};

int main()
{
    QuickSort qs;
    qs.init();
    return 0;
}
