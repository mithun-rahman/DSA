#include<bits/stdc++.h>

using namespace std;

class Heap
{
    public:
        int nextFree = 1;
        int heap[103];

        void push(int val)
        {
            heap[nextFree++] = val;
            if(nextFree > 2) {
                int pos = nextFree - 1;
                while(pos > 1 && (heap[pos] > heap[pos/2])) {
                    swap(heap[pos], heap[pos/2]);
                    pos = pos/2;
                }
            }
        }
        void heapify(int pos)
        {
            int n, l, r, mx;
            n = nextFree - 1;
            l = pos*2;
            r = pos*2 + 1;

            while(l <= n && r <= n) {
                mx = max(heap[l], heap[r]);
                if(heap[pos] > mx) return ;
                if(mx == heap[l]) {
                    swap(heap[pos], heap[l]);
                    pos = l;
                }
                else {
                    swap(heap[pos], heap[r]);
                    pos = r;
                }
                l = pos*2;
                r = pos*2 + 1;
            }
            if(l <= n) {
                if(heap[pos] < heap[l]) swap(heap[pos], heap[l]);
            }
        }

        void pop()
        {
            swap(heap[1], heap[nextFree-1]);
            nextFree = nextFree - 1;
            heapify(1);
        }

        void print()
        {
            for(int i = 1; i < nextFree; i++) {
                cout << heap[i] << ' ';
            }
            cout << endl;
        }
};

int main()
{
    Heap hp;
//    hp.push(40);
//    hp.push(20);
//    hp.push(15);
//    hp.push(10);
//    hp.push(30);

    hp.heap[1] = 10;
    hp.heap[2] = 20;
    hp.heap[3] = 15;
    hp.heap[4] = 30;
    hp.heap[5] = 40;


    hp.nextFree = 6;
    for(int i = 5; i >= 1; i--) {
        hp.heapify(i);
    }

    hp.pop();
    hp.pop();
    cout << hp.heap[1] << endl;

    return 0;
}
