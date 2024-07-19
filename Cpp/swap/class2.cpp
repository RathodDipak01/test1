#include<iostream>
using namespace std;

class A;     //forward decleration
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
    void swap(A&);
   
};

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
    friend void B::swap(A&);
};

void B::swap(A&p)
{
    int r=p.a;
    p.a=b;
    b=r;
}

int main()
{
    A obja;
    B objb;
    obja.set();
    objb.set();
    obja.display();
    objb.display();
    objb.swap(obja);
    obja.display();
    objb.display();
    return 0;
} 

