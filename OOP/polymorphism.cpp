#include<bits/stdc++.h>

using namespace std;

class A
{
    public:
        int a;

        void hello()
        {
            cout << "Hello A" << endl;
        }

        int add(int x, int y)   /// function overloading
        {
            return x + y;
        }
        int add(int x)
        {
            return x + x;
        }

        int operator+ (A &obj)   /// operator overloading
        {
            int val1 = this->a;
            int val2 = obj.a;

            return val2 - val1 ;
        }
};

class B:public A
{
    public:
    void hello()                       /// function overriding
    {
        cout << "Hello B" << endl;
    }
};

int main()
{
    B obj;
    obj.hello();
    return 0;
}
