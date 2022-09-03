#include<bits/stdc++.h>

using namespace std;

class QuickSort
{
    private:
        int arr[102];

        void quicksort(int lo, int hi)
        {
            if(lo >= hi) return ;

            int s = lo;
            int e = hi;
            int mid = lo + (hi-lo)/2;
            int pivot = arr[mid];

            while(s <= e) {
                while(arr[s] < pivot) {
                    s++;
                }
                while(arr[e] > pivot) {
                    e--;
                }
                if(s <= e) {
                    swap(arr[s], arr[e]);
                    s++;
                    e--;
                }
            }
            quicksort(lo, e);
            quicksort(s, hi);
        }

    public:
        void init()
        {
            arr[1] = 1; arr[2]= 4; arr[3]=5; arr[4]=3; arr[5]=2;arr[6]=6;
            quicksort(1, 6);
            for(int i = 1; i <= 6; i++) {
                cout << arr[i] <<" ";
            }
            cout << endl;
        }
};

int main()
{
    QuickSort qs;
    qs.init();
    return 0;
}
