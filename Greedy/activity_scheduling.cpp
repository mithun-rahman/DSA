// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:

    static bool cmp(vector<int>&a,vector<int>&b){ return a[1]<b[1];}
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> vt;
        for(int i = 0;i < n; i++) {
            vt.push_back({start[i], end[i]});
        }
        sort(vt.begin(),vt.end(),cmp);
        int cnt = 0, last = -1;
        for(int i = 0; i < n; i++) {
            if(vt[i][0] > last) {
                cnt++;
                last = vt[i][1];
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
