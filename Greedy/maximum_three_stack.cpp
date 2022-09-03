#include<bits/stdc++.h>

using namespace std;

class Solution{
     private:
    int maxThree(int a, int b, int c)
    {
        if(a >= b && a >= c) return a;
        if(b >= a && b >= c) return b;
        return c;
    }
    public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1, sum2, sum3, i, j, k;
        sum1 = sum2 = sum3 = 0;
        for(i = 0; i < N1; i++) {
            sum1 += S1[i];
        }
        for(i = 0; i < N2; i++) {
            sum2 += S2[i];
        }
        for(i = 0; i < N3; i++) {
            sum3 += S3[i];
        }
        i = j = k = 0;

        if(sum1 == sum2 && sum2 == sum3) {
            return  sum1;
        }
        while(i < N1 && j < N2 && k < N3) {
            int top = maxThree(sum1,  sum2, sum3);
            cout << sum1 << " "<< sum2 << " "<< sum3 << " - "<< " "<< top << endl;
            if(top == sum1) {
                sum1 -= S1[i++];
            }
            else if(top == sum2) {
                sum2 -= S2[j++];
            }
            else if(top == sum3) {
                sum3 -= S3[k++];
            }
            if(sum1 == sum2 && sum2 == sum3) {
                return  sum1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution ss;
    vector<int> v1, v2, v3;
    v1 = {12, 14, 16, 9, 18, 7, 2, 5, 2, 9};
    v2 = {18, 19, 18, 9, 13, 1, 19, 5, 5};
    v3 = {17, 15, 7, 19, 20, 4 ,12, 7};
    cout << ss.maxEqualSum(10, 9, 8, v1, v2, v3) << endl;
    return 0;
}
