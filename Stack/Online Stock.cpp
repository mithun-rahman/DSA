#include<bits/stdc++.h>

using namespace std;

class StockSpanner {
    public:
        stack<int> st;
        vector<int> vt;
        StockSpanner() {

        }

        int next(int price) {
            vt.push_back(price);
            while(st.size() && price >= vt[st.top()]) {

                st.pop();
            }
            int res;
            if(st.size() == 0) res = vt.size();
            else res = vt.size() - st.top()-1 ;
            st.push(vt.size()-1);

            return res;
        }
        void solution()
        {
            cout << next(100) << endl;
            cout << next(80) << endl;
            cout << next(60) << endl;
            cout << next(70) << endl;

            cout << next(60) << endl;
            cout << next(75) << endl;
            cout << next(85) << endl;
//            cout << next(70) << endl;
        }
};

int main()
{
//    StockSpanner sp;
//    sp.solution();
    string str = "45";
      int num = stoi(str);
      cout << num + 5 << endl;
     return 0;
}
