#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        struct node
        {
            int val, fr;
        }heap[1000004];

        int nextFree = 1;

    public:
        void Swap(int l, int r)
        {
            node temp = heap[l];
            heap[l] = heap[r];
            heap[r] = temp;
        }

        void add(int val, int fr)
        {
            heap[nextFree].val = val;
            heap[nextFree].fr = fr;
            nextFree++;

            if(nextFree > 2) {
                int pos = nextFree - 1;
                while(pos > 1 && (heap[pos].fr < heap[pos/2].fr)) {
                    Swap(pos, pos/2);
                    pos = pos / 2;
                }
            }
        }

        void heapify(int pos)
        {
            int l, r, mn, n;
            n = nextFree - 1;
            l = pos*2;
            r = pos*2 + 1;
            while(l <= n && r <= n) {
                mn = min(heap[l].fr, heap[r].fr);
                if(heap[pos].fr < mn) return ;
                if(mn == heap[l].fr) {
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
            if(l <= n && (heap[pos].fr > heap[l].fr)) {
                Swap(l, pos);
            }
        }

        void pop()
        {
            Swap(1, nextFree-1);
            nextFree--;
            heapify(1);
        }

        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            for(int i = 0; i < nums.size(); i++) {
                mp[nums[i]]++;
            }
            int cnt = 1;
            for(auto &it:mp) {
//                cout << it.first << " "<<it.second << endl;
                if(cnt <= k) {
                    add(it.first, it.second);
                }
                else {
                    if(heap[1].fr < it.second) {
                        //cout << it.first << " "<<it.second << endl;
                        heap[1].val = it.first;
                        heap[1].fr = it.second;
                        heapify(1);
                      //  print();
                    }
                }
                cnt++;
            }

            for(int i = 1; i <= k; i++) {
                cout << heap[i].val << endl;
            }

            return {};
        }
        void print()
        {
            for(int i = 1; i < nextFree; i++) {
                cout << heap[i].val << " " << heap[i].fr << endl;
            }
        }
};

int main()
{
    vector<int> vt;
    vt = {1,1,1,2,2,3, 5, 5, 6, 7};

    Solution ss ;

    ss.topKFrequent(vt, 2);

    ss.print();
    return 0;
}
