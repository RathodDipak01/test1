#include<iostream>
using namespace std;

class B;     //forward decleration
class A
{
    int a;
    public:
    void set()
    {
        cout<<"\n A a:";
        cin>>a;
    }
    void display()
    {
        cout<<"\nA a:"<<a;
    }
    void swap(B&);
};

class B
{
    int b;
    public:
    void set()
    {
        cout<<"\n B b:";
        cin>>b;
    }
    void display()
    {
        cout<<"\nB b:"<<b;
    }
    friend void A::swap(B&);
};

void A::swap(B&q)
{
    int r=a;
    a=q.b;
    q.b=r;
}

int main()
{
    A obja;
    B objb;
    obja.set();
    objb.set();
    obja.display();
    objb.display();
    obja.swap(objb);
    obja.display();
    objb.display();
    return 0;
} 

