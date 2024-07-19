#include <iostream>
using namespace std;
class Number
{
    int no;

public:
    Number()
    {
        no = 0;
    }
    Number(int a)
    {
        no = a;
    }
    Number(Number &t)
    {
        no = t.no;
    }
    ~Number() {}

    friend istream &operator>>(istream &kin, Number &t)
    {
        cout << "\n No:";
        kin >> t.no;
        return kin;
    }

    friend ostream &operator<<(ostream &kout, Number &t)
    {
        kout << "\n No:" << t.no;
        return kout;
    }

    Number operator+(int a)
    {
        Number k(no + a);
        return k;
    }

    Number operator-(int a)
    {
        Number k(no - a);
        return k;
    }

    Number operator+=(int a)
    {
        no = no + a;
        return * this;
    }

    Number operator-=(int a)
    {
        no = no - a;
        return * this;
    }


    friend Number operator+(int n, Number & a)
    {
        Number t(n+a.no);
        return t;
    }

    friend Number operator-(int n, Number & a)
    {
        Number t(n-a.no);
        return t;
    }

    void operator -()
    {
        no=-no;
    }


    Number operator ++()    //pre-increment
    {
        Number k(++no);
        return k;
    }


     Number operator ++(int)    //post-increment
    {
        Number k(no++);
        return k;
    }

};

int main()
{
    Number p, q, r;
    cin >> p ;
    cout << p ;
    q=p+3;
    cout<<q;
    p+=4;
    cout<<p;
    r=3+p;
    cout<<r;
    -r;
    cout<<r;
    r=++p;
    cout<<p<<r;
    r=p++;
    cout<<p<<r;
}