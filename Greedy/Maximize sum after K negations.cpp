#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        sort(arr, arr+n);
        for(int i = 0;i < n; i++) {
            if(k && arr[i] < 0) {
                arr[i] = -arr[i];
                k--;
            }
        }
        sort(arr, arr+n);
        long long sum = 0;
        for(int i = 0;i < n; i++) {
            sum += arr[i];
        }
        if(k % 2) sum -= arr[0];
        return sum;
    }
};


int main()
{
    Solution ss;
    long long arr[100];
    for(int i = 0; i < 5; i++) arr[i] = i+1;
    cout << ss.maximizeSum(arr, 5, 5) << endl;
    return 0;
}
