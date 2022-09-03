#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        struct node
        {
            char ch;
            int fr;
        }heap[55];

        int nextFree ;

    public:
        void Swap(int l, int r)
        {
            node temp = heap[l];
            heap[l] = heap[r];
            heap[r] = temp;
        }

        void heapify(int pos)
        {
            int l, r, mx, n;
            n = nextFree - 1;
            l = pos*2;
            r = pos*2 + 1;
            while(l <= n && r <= n) {
                mx = max(heap[l].fr, heap[r].fr);
                if(heap[pos].fr > mx) return ;
                if(mx == heap[l].fr) {
                    Swap(l, pos);
                    pos = l;
                }
                else {
                    Swap(r, pos);
                    pos = r;
                }
                l = pos*2;
                r = pos*2 + 1;
            }
            if(l <= n && (heap[pos].fr < heap[l].fr)) {
                Swap(l, pos);
            }
        }

        void pop()
        {
            Swap(1, nextFree-1);
            nextFree--;
            heapify(1);
        }

        string frequencySort(string s) {
            unordered_map<int, int> mp;
            for(int i = 0; i < s.size(); i++) {
                mp[s[i]]++;
            }
            nextFree = 1;
            for(auto &it:mp) {
                heap[nextFree].ch = it.first;
                heap[nextFree].fr = it.second;
                nextFree++;
            }
            heapify(1);
            for(int i = nextFree-1; i >= 1; i--) {
                heapify(i);
            }
            int n = nextFree ;
            string ss = "";
            for(int i = 1; i < n; i++) {
                for(int j = 1; j <= heap[1].fr; j++) {
                    ss += heap[1].ch;
                }
                pop();
            }
            cout << ss << endl;
            return ss;
        }

};

int main()
{
    Solution ss ;

    ss.frequencySort("Aabb");

    return 0;
}
