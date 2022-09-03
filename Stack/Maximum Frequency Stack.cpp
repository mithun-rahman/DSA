#include<bits/stdc++.h>

using namespace std;

class FreqStack {

    public:
        int mx;
        stack<int> st[20004];
        unordered_map<int,int> mp;

        FreqStack() {
            mx = 0;
        }

        void Print(stack<int> st)
        {
            while(st.size()) {
                cout << st.top() <<" ";
                st.pop();
            }
            cout << endl;
        }

        void push(int val) {
            mp[val]++;
            st[mp[val]].push(val);
            mx = max(mx, mp[val]);
        }

        int pop() {
            int val = st[mx].top();
            mp[val]--;
            st[mx].pop();
            if(st[mx].size() == 0) mx--;
            return val;

        }
        void solve()
        {
            FreqStack();
            push(4);
            push(9);
            push(0);
            push(3);
            push(4);
            push(2);

            cout << pop() << endl;

            push(6);

            cout << pop() << endl;
            push(1);
            cout << pop() << endl;
            push(1);
            cout << pop() << endl;

            push(4);
            Print(st[2]);
            cout << pop() << endl;
            cout << pop() << endl;

        }
};


int main()
{
    FreqStack fs;
    fs.solve();
    return 0;
}
