#include<bits/stdc++.h>

using namespace std;

class Hero
{
    private:
        string name;
        int age;
    public:
        int getAge()
        {
            return this->age;
        }
        void setAge(int age)
        {
            this->age = age;
        }

};

int main()
{
    Hero h1;
    h1.setAge(45);
    cout << h1.getAge() << endl;
    return 0;
}
