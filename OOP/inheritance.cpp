#include<bits/stdc++.h>

using namespace std;

class Human
{
    public:
    int height;
    int weight;
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

class Male:private Human
{
    public:
    string color;

    public:
    void sleep()
    {
        cout << "Male sleeping" << endl;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }

    int getWeight()
    {
        return this->weight;
    }
};

int main()
{
    Male ob;

    ob.setWeight(45);
    cout << ob.getWeight() << endl;
    return 0;
}
