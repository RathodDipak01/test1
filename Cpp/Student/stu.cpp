#include <iostream>
using namespace std;

class stu
{
    int no;
    char nm[15];
    int mrk;

public:
    stu()  
    {
        no=mrk=0;
        nm[0]='\0';
    } 

    stu(stu & s)
    {
        no=s.no;
        mrk=s.mrk;
        strcpy(nm, s.nm);
    }
    ~stu(){}

    void setData()
    {
        cout<<"\n Roll No:"; cin>>no;
        cout<<"\n Name"; cin>>nm;
        cout<<"\n Marks:"; cin>>mrk;
    } 

    void display()
    {
        cout<<"\n Roll No: "<<no<<" \n Name: "<<nm <<"\n Marks: "<<mrk;
    }


    int operator >(int a){ return mrk>a;}
    int operator <(int a){ return mrk < a;}
    int operator==(int a)
    {
        return (mrk==a);
    }

     int operator >(stu & k)
    {
        return (no> k.no);
    }
    int operator<(stu & k)
    {
        return (no<k.no);
    }


    stu operator+(int a)
    {
        stu tmp;
        tmp.no=no;
        strcpy(tmp.nm,nm);
        tmp.mrk=mrk+a;
        return tmp;
    }

     stu operator-(int a)
    {
        stu tmp;
        tmp.no=no;
        strcpy(tmp.nm,nm);
        tmp.mrk=mrk-a;
        return tmp;
    }
};

// int main()
// {
//     stu s;
//     s.setData();
//     s.display();
//     if(s>70)
//     {
//         cout<<"\n Pass";
//     }
//     else{
//         cout<<"\n Repeat";
//     }

//     if(s==23)
//     cout<<"\n Match";
//     else{
//         cout<<"\n No match";
//     }
// }

int main()
{
    stu s,p,r;
    s.setData();
    p.setData();
   s.display();
   r=s+5;
   r.display();
   s.display();
   r.display();
}
