#include<bits/stdc++.h>

using namespace std;

class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {
	    long long mx = INT_MIN;
	    long long prefix, suffix;
	    prefix = suffix = 1;
	    for(int i = 0; i < n; i++) {
	        prefix = prefix*arr[i];
	        suffix = suffix*arr[n-i-1];
	        mx = max(mx, max(prefix, suffix));
	        if(arr[i] == 0) {
                prefix = 1;
	        }
	        if(arr[n-i-1] == 0) {
                suffix = 1;
	        }
	    }
	    return mx;
	}
};


int main()
{
    vector<int> vt;
    vt = {6, -3, -10, 0, 2};
    Solution ss;
    cout << ss.maxProduct(vt, 5) << endl;
    return 0;
}
