#include"array.h"
class Result
{
    int rno;
    MyData mrk;

    public:
    void init()
    {
        rno=0;
        mrk.init();
    }
    void setData(int no)
    {
        rno=no;
        mrk.setData();
    }
    void setData()
    {
        cout<<"\nRoll No:";
        cin>rno;
        cout<<"\n Marks:";
        mrk.setData();
    }

    void display()
    {
        cout<<"\nRoll No:"<<rno;
        cout<,"\nMarks:";
        mrk.Dispaly();
        cout<<"\nTotal:"<<mrk.total();
        cout<<"\nAvg:"<<mrk.avg();
    }
    int getTotal()
    {
        return mrk.total();
    }

    int getAvg()
    {
        return mrk.avg();
        }

    int getNo()
    {
        return rno;
    }

    int isMore(int a)
    {
        return (getTotal()>a);
    }    

    int isLess(int a)
    {
        return (getTotal()<a);
    }

      int isMore(Result & b)
    {
        return (getTotal()>b.getTotal());
    }    

    int isLess(Result & b)
    {
        return (getTotal()<b.getTotal());
    }
};

void main()
{
    Result a,b;
    a.setData();
    b.setData();

    a.display();
    b.display();

    if(a.isMore(90))
    cout<<"\nAclass";
    else
    cout<<"\n other class";

    if(a.isMore(b))
    a.display();
    else
    b.display();
    return;
}