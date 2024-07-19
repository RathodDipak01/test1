//mytime.h

#include <iostream>
using namespace std;

class MyTime
{
    int h,m,s;
    long int toSeconds()
    {
        return h*3600l+m*60+s;
    }

    public:
    MyTime()
    {
        h=m=s=0;
    }

    MyTime(int a,int b=0, int c=0)
    {
        h=a;m=b;s=c;
    }

    MyTime(long int a)
    {
        h=a/3600;
        a=a%3600;
        m=a/60;
        s=a%60;
    }

    MyTime(MyTime & a )
    {
        h=a.h;
        m=a.m;
        s=a.m;
    }
    ~MyTime(){}

    int getHr(){return h;}
    int getMn(){return m;}
    int getSs(){return s;}

    void setTime()
    {
        cout<<"\n Hr:"; cin>>h;
        cout<<"\n Mn:"; cin>>m;
        cout<<"\n Ss:"; cin>>s;
    }

    void setTime(int a,int b=0, int c=0)
    {
        h=a;m=b;s=c;
    }

    void setTime(long int a)
    {
        h=a/3600;
        a=a%3600;
        m=a/60;
        s=a%60;
    }

    void setTime(MyTime &a)
    {
        h=a.h;
        m=a.m;
        s=a.s;
    }
    void display()
    {
        cout<<h<<"\t"<<m<<"\t"<<s<<"\n";
    }

    MyTime add(MyTime &q)
    {
        long int a=toSeconds();
        long int b=q.toSeconds();
        long int c=a+b;
        MyTime k(c);
        return k;
    }


     MyTime sub(MyTime &q)
    {
        long int a=toSeconds();
        long int b=q.toSeconds();
        long int c=labs(a-b);
        MyTime k(c);
        return k;
    }


    int isMore(MyTime &t)
    {
        return toSeconds()>t.toSeconds();
    }
    int isLess(MyTime & t)
    {
        return toSeconds()<t.toSeconds();
    }
};
