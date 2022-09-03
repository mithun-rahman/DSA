#include<bits/stdc++.h>

using namespace std;

bool mark[103];
vector<int> prime;
int N = 40;

void Seive()
{
    prime.push_back(2);
    int limit = sqrt(N) + 1;

    for(int i = 3; i <= N; i += 2) {
        if(mark[i] == 0) {
            prime.push_back(i);
            if(i <= limit) {
                for(int j = i*i; j <= N; j += 2*i) {
                    mark[j] = 1;
                }
            }
        }
    }
}

double Sqrt(double n)
{
    double lo, hi;
    lo = 0;
    hi = n;
    for(int i = 1; i <= 100; i++) {
        double mid = (lo + hi) / 2;
        if(mid*mid > n) hi = mid ;
        else lo = mid ;
    }
    return lo;
}

int main()
{
    Seive();
//    for(int i = 0; i < prime.size(); i++) {
//        cout << prime[i] << " ";
//    }
    cout << Sqrt(100.00) << endl;
    return 0;
}
