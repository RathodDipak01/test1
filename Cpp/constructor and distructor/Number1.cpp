#include <iostream>
using namespace std;

const int M = 10;

class Array
{
    int x[M];

public:
    Array();
    Array(int);
    Array(Array &);
    ~Array() {}
    void setData();
    void setData(Array &);
    void display();
    int total();
    int avg() { return total() / M; }
};


Array::Array()
{
    for(int i=0;i<M;i++)
    x[i]=0;
}

Array::Array(int val)
{
    for(int i=0; i<M; i++)
    x[i]=val;
}

Array::Array(Array &t)
{
    for(int i=0; i<M;i++)
    x[i]=t.x[i];
}

void Array::setData()
{
    cout<<"\n Enter Array Data\n";
    for(int i=0;i<M;i++)
    cin>>x[i];
}

void Array::display()
{
    cout<<"\n Data";
    for(int i=0;i<M;i++)
    cout<<" "<<x[i];
}


int Array::total()
{
    int tot=x[0],i=1;
    while(i<M)
    tot+=x[i++];
    return tot;
}


void Array::setData(Array & t)
{
    for(int i=0;i<M;i++)
    x[i]=t.x[i];
}


int main()
{
    Array p;
    p.setData();
    p.display();
    cout << "Total: " << p.total() ;
    cout << "Average: " << p.avg() ;
    return 0;
}