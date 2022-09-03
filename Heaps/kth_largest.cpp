#include<bits/stdc++.h>

using namespace std;

class Heap
{
    public:

        void heapify(vector<int>& nums, int pos)
        {
            int l, r, mx, n;
            l = pos*2 + 1;
            r = pos*2 + 2;
            n = nums.size() - 1;

            while(l <= n && r <= n)
            {
                mx = max(nums[l], nums[r]);
                if(nums[pos] > mx) return;
                if(mx == nums[l]) {
                    swap(nums[pos], nums[l]);
                    pos = l;
                }
                else {
                    swap(nums[pos], nums[r]);
                    pos = r;
                }
                l = pos*2 + 1;
                r = pos*2 + 2;
            }
            if(l <= n && (nums[pos] < nums[l])) {
                swap(nums[pos], nums[l]);
            }
        }
        /// using max heap
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            for(int i = n-1; i >= 0; i--) {
                heapify(nums, i);
            }

            for(int i = 0; i < k-1; i++) {
                pop(nums);
            }
            return nums[0];
        }

        void  pop(vector<int>& nums)
        {
            swap(nums[0], nums[nums.size()-1]);
            nums.pop_back();
            heapify(nums, 0);
        }

        void print(vector<int> &nums)
        {
            for(int i = 0; i < nums.size(); i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        void MinHeap(vector<int> &heap)
        {

        }

};

int main()
{
    Heap hp;

    vector<int> vt;
    vt.push_back(3);
    vt.push_back(2);
    vt.push_back(1);
    vt.push_back(5);
    vt.push_back(6);
    vt.push_back(4);

    cout << hp.findKthLargest(vt, 2) << endl;
  //  vt.push_back(4);
//
//    for(int i = vt.size()-1; i >= 0; i--) {
//        hp.heapify(vt, i);
//    }
//
//    hp.print(vt);
    return 0;
}
