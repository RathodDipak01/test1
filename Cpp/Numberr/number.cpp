#include <iostream>
using namespace std;
class Number
{
    int no;
    public:
    Number()
    {
        no=0;
    }
    Number(int a)
    {
        no=a;
    }
    Number (Number &t)
    {
        no=t.no;
    }
    ~Number(){}

    friend istream & operator >>(istream & kin, Number & t)
    {
        cout<<"\n No:";
        kin>>t.no;
        return kin;
    }

    friend ostream & operator << (ostream & kout, Number & t)
    {
        kout<<"\n No:"<<t.no;
        return kout;
    }
};


int main()
{
    Number p,q;
    cin>>p>>q;
    cout<<p<<q;
}