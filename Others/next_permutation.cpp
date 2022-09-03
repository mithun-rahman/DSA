#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int F, S;
        F = -1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                F = i;
                break;
            }
        }
        if(F == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for(int i = n-1; i >= 0; i--) {
                if(nums[i] > nums[F]) {
                    S = i;
                    break;
                }
            }
            swap(nums[F], nums[S]);
            reverse(nums.begin()+F+1, nums.end());
        }
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] <<" ";
        }
        cout << endl;
    }
};

int main()
{
    Solution ss;
    vector<int> vt;
    vt = {1,4, 5, 3, 2};
    ss.nextPermutation(vt);
    return 0;
}
