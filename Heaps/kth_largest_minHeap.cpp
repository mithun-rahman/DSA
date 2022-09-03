#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        void heapify(vector<int> &vt)
        {
            int n, l, r, mn, pos;
            pos = 0;
            n = vt.size()-1;

            l = pos*2 + 1;
            r = pos*2 + 2;

            while(l <= n && r <= n) {
                mn = min(vt[l], vt[r]);
                if(vt[pos] < mn) return ;
                if(mn == vt[l]) {
                    swap(vt[pos], vt[l]);
                    pos = l;
                }
                else {
                    swap(vt[pos], vt[r]);
                    pos =  r;
                }
                l = pos*2+1;
                r = pos*2+2;
            }
            if(l <= n && (vt[pos] > vt[l])) {
                swap(vt[pos], vt[l]);
            }
        }

        void MinHeap(vector<int> &vt, int val)
        {
            vt.push_back(val);

            if(vt.size() > 1) {
                int pos = vt.size()-1;
                while(pos > 0 && (vt[pos] < vt[(pos-1)/2])) {
                    swap(vt[pos], vt[(pos-1)/2]);
                    pos = (pos-1)/2;
                }
            }
        }

        int findKthLargest(vector<int>& nums, int k) {

            vector<int> vt;
            for(int i = 0; i < k; i++) {
                MinHeap(vt, nums[i]);
            }

            for(int i = k; i < nums.size(); i++) {
                if(nums[i] > vt[0]) {
                    vt[0] = nums[i];
                    heapify(vt);
                }
            }
            return vt[0];
        }
};

int main()
{
//    Solution hp;
//    vector<int> vt;
//    vt.push_back(1);
//    vt.push_back(3);
//    vt.push_back(4);
//    vt.push_back(7);
//
//    cout <<hp.findKthLargest(vt, 2) << endl;

    priority_queue<int> pq;
    pq.push(-4);
    pq.push(-5);
    cout <<pq.top() << endl;

    return 0;
}
