#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cnt ;
    int arr[50004], temp[50003];

    void mergeSort(int lo, int hi)
    {
        if(lo == hi) return ;
        int mid = (lo+hi)/2;

        mergeSort(lo, mid);
        mergeSort(mid + 1, hi);

        int i, j, k;
        i = lo; j = mid + 1;
        while(i <= mid && j <= hi) {
            if(arr[i] > 2LL*arr[j]) {
                cnt += (mid-i+1);
                cout << lo <<" " << hi <<" "<< i <<" "<< j << endl;
                j++;
            }
            else i++;
        }

        for(int i = lo, j=mid+1, k=lo; k <= hi; k++) {
            if(i == mid+1) temp[k] = arr[j++];
            else if(j == hi+1) temp[k] = arr[i++];
            else if(arr[i] < arr[j]) temp[k] = arr[i++];
            else temp[k] = arr[j++];
        }
        for(int k = lo; k <= hi; k++) arr[k] = temp[k];
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        for(int i = 0;i < nums.size(); i++) arr[i+1]=nums[i];

        mergeSort(1, nums.size());

        for(int i = 1;i <= nums.size(); i++) cout << arr[i] <<" ";
        cout << endl;

        return cnt;
    }
};

int main()
{
    Solution ms;
    vector<int> vt;
    vt = {1, 1, 1, 1, 1};
    cout << ms.reversePairs(vt) << endl;
    return 0;
}
