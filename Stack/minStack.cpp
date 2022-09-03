#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> st, support;
    MinStack() {

    }

    void push(int val) {
        st.push(val);
        if(support.size()) {
            if(support.top() > val) {
                support.pop();
                support.push(val);
            }
        }
        else {
            support.push(val);
        }
    }

    void pop() {
        int val = st.top();
        st.pop();
        if(val == support.top()) {
            support.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return support.top();
    }
};

int main()
{
    return 0;
}
