#include<bits/stdc++.h>

using namespace std;

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1,...,xN
(0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards
each other once put into a stall To prevent the cows from hurting each other FJ wants
to assign the cows to the stalls,such that the minimum distance between any two of them
is as large as possible.
What is the largest minimum distance?
*/

class Solution
{
    private:
        int split(vector<int> vt, int dist)
        {
            int cnt, prev;
            prev = vt[0];
            cnt = 1;
            for(int i = 1; i < vt.size(); i++) {
                if(vt[i] - prev >= dist) {
                    prev = vt[i];
                    cnt++;
                }
            }
            return cnt;
        }

    public:
        int Aggressive(vector<int> vt, int cow)
        {
            int lo, hi, mid;
            lo = 0; hi = vt[vt.size()-1] ;
            while(hi > lo) {
                mid = (lo + hi + 1) / 2;
                if(split(vt, mid) >= cow) {
                    lo = mid;
                }
                else {
                    hi = mid - 1;
                }
            }
            return lo;
        }
};

int main()
{
    Solution ss;
    vector<int> vt;
    int k = 3;
    vt = {1, 2, 8, 4, 9};
    sort(vt.begin(), vt.end());
    cout << ss.Aggressive(vt, k) << endl;
    return 0;
}
