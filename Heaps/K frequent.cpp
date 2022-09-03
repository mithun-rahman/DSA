#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        struct node
        {
            int val, fr;
        }heap[1000004];

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

        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            for(int i = 0; i < nums.size(); i++) {
                mp[nums[i]]++;
            }
            nextFree = 1;
            for(auto &it:mp) {
                heap[nextFree].val = it.first;
                heap[nextFree].fr = it.second;
                nextFree++;
            }
            heapify(1);
            for(int i = nextFree-1; i >= 1; i--) {
                heapify(i);
            }
            vector<int> vt;
            for(int i = 1; i <= k; i++) {
                vt.push_back(heap[1].fr);
                pop();
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
