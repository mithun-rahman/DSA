#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    string smallestNumber(int S, int D){
        vector<int> digit;
        if(S % 9) digit.push_back(S % 9);
        for(int i = 1; i <= S/9; i++) {
            digit.push_back(9);
        }
        string res = "";
        if(digit.size() > D) res = "-1";
        else {
            if(D - digit.size()) {
                res = "1";
                digit[0]--;
            }
            int zr = D - digit.size() - 1;
            if(zr < 0) zr = 0;
            while(zr) {
                res += "0";
                zr--;
            }
            for(int i = 0; i < digit.size(); i++) {
                res += (digit[i] + 48);
            }
        }
        return res;
    }
    int minSubset(vector<int> &Arr,int N){
        long long sum1, sum2;
        sum1 = 0;
        for(int i = 0; i < N; i++) {
            sum1 += Arr[i];
        }
        int cnt ;
        sum2 = cnt = 0;
        sort(Arr.begin(), Arr.end());

        for(int i = N-1; i >= 0; i--) {
            sum2 += Arr[i];
            cnt++;
            sum1  -= Arr[i];

            if(sum2 > sum1) {
                cout << cnt << endl;
                return cnt;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution ss;

    vector<int>vt;
    vt = {0};
    cout << ss.minSubset(vt, 1) << endl;
    return 0;
}
