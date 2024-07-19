#include <iostream>
#include "array.h"
using namespace std;
void main()
{
class newresult
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

    int isLess(int no, int flg=0)
    {
        if (flg=0)
        return(getTotal()<no);
        else
        return(rno<no);
    }    

    int isMore(int no, int flg=0)
    {
        if(flg=0)
        return(getTotal()>no);
        else
        return(rno>no);
    }

      int isMore(newresult & b)
    {
        return (getTotal()>b.getTotal());
    }    

    int isLess(newresult & b)
    {
        return (getTotal()<b.getTotal());
    }
};

/*void main()
{
    newresult a,b;
    a.setData();
    b.setData();

    a.display();
    b.display();

    if(a.isMore(90))
    cout<<"\n>90 Marks";
    else
    cout<<"\n <=90 Marks";

    if(a.isMore(23,1))
    cout<<"\n RECORD MATCH";
    else
    cout<<"\n Record not match ";
}*/

void main ()
{
    newresult p[5];
    int i=0,j,pos;
    newresult tmp;
    while(i<5)
    {
        p[i].setData();
        i++;
    }
    for(i=0;i<5;i++)
    p[i].display();
    
    for(i=0;i<4;i++)
    {
        pos=i;
        for(j=i+1;j<5;j++)
        {
            if(p[j].isLess(p[pos]))
            pos=j;
        }
        if(i!=pos)
        {
            tmp=p[i];
            p[i]=p[pos];
            p[pos]=tmp;
        }
    }
    for(i=0;i<5;i++)
    p[i].display();
    }

    return;
}