#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        double Power(double a, int b)
        {
            double res = 1.0;
            for(int i = 1; i <= b; i++) {
                res = res * a;
            }
            return res;
        }
        double NthRoot(int a, int b)
        {
            double lo, hi, mid;
            lo = 0; hi = a;
            for(int i = 0; i <= 200; i++) {
                mid = (lo+hi)/2;
                if(Power(mid, b) > a) hi = mid;
                else lo = mid;
            }
            return mid;
        }
    public:
        double Result(int a, int b)
        {
            return NthRoot(a, b);
        }
};

int main()
{
    Solution ss;
    cout << ss.Result(27, 3) << endl;
    return 0;
}
