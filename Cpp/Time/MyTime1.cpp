
#include"MyTime.h"
#include<iostream>
#include<cstring>
using namespace std;

class Emp
{

    int eno;
    char enm[15];
    int esalph;
    MyTime ewt;
    int estate;      // 0-invalid  1-Valid

    public:
    Emp()
    {
        eno=esalph=0;
        estate=1;
        enm[0]='\0';
    }

    Emp(Emp & a)
    {
        eno=a.eno;
        esalph=a.esalph;
        estate=a.estate;
        strcpy(enm, a.enm);
        ewt=a.ewt;
    }

    ~Emp(){}
    int getNo(){return eno;}
    int getSalary()
    {
        return esalph*ewt.getHr();
    }
    int getState(){return estate;}
    char*getName(){return enm;}
    MyTime getTime(){return ewt;}


    void display()
    {
        cout<<"\n No: "<<eno;
        cout<<"\n Name: "<<enm;
        cout<<"\n Work Time: ";
        ewt.display();
        cout<<"\n Salary Per Hr: "<<esalph;
        cout<<"\n State: "<<estate;
    }

    void setData(int a)
    {
        eno=a;
        cout<<"\n Name:";
        cin>>enm;
        cout<<"\n Work Time:";
        ewt.setTime();
        cout<<"\n Enter Salary Per Hr:";
        cin>>esalph;
        estate=1;
    }      
     void edelete()
    {
        estate=0;
    }

};

// int main() {
//     Emp emp1;
//     emp1.setData(1);
//     emp1.display();
    
//     cout << "\nSalary: " << emp1.getSalary() << endl;

//     emp1.edelete();
//     cout << "\nAfter delete operation: ";
//     emp1.display();

//     return 0;
// }




// int main(){
//     Emp p[5];
//     for(int i=0; i<5;i++)
//     {
//     p[i].setData(i+1);
//     }

//     for(int i=0; i<5;i++)
//     {
//     p[i].display();
//     }
// }



#define M 10
class EmpAMD
{
    Emp p[M];
    int lpos;

    public:
    EmpAMD()
    {
        lpos= -1 ;
    }
    ~EmpAMD(){}
    int search(int no);
    void add();
    void mod();
    void del();
    void display();
    void menu();
};



// to search
int EmpAMD::search(int no)
{
    int i=0;
    while(i<=lpos)
    {
        if(p[i].getNo()==no)
        break;
        i++;
    }
    if(i>lpos){
        return -1;     //Not Found
    }
     else
    return i;
    
}


// to add
void EmpAMD::add()
{
    int no,res;
    if(lpos==(M-1))
    {
        cout<<"\n Overflow";
        return;
    }
    cout<<"\nEmployee No:";
    cin>>no;
    res=search(no);
    if(res>=0)
    {
        cout<<"\n Recode Exists";
        return;
    }
    lpos++;
    p[lpos].setData(no);     //record inserted at the end
}



void EmpAMD::mod()
{
    int no,res;
    if(lpos==9)
    {
        cout<<"\n Overflow";
        return;
    }
    cout<<"\nEmployee No:";
    cin>>no;
    res=search(no);
    if(res>=0)
    {
        cout<<"\n REcode Exists";
        return;
    }
    lpos++;
    p[lpos].setData(no);     //record inserted at the end
}




//to delete
void EmpAMD::del()
{
    int no,res;
    if(lpos==9)
    {
        cout<<"\n Overflow";
        return;
    }
    cout<<"\nEmployee No:";
    cin>>no;
    res=search(no);
    if(res>=0)
    {
        cout<<"\n REcode Exists";
        return;
    }
    lpos++;
    p[lpos].edelete();     //record Deleted
}




void EmpAMD::display()
{
    if(lpos==-1)
    {
        cout<<"\n No Records";
        return;
    }
    for(int i=0;i<=lpos;i++)
    p[i].display();
}





void EmpAMD::menu()
{
    int opt;
    while(1)
    {
        cout<<"\n MEnu \n 1.Add \n 2.Mod \n 3.Del \n 4.Display \n 5.Exit \n Option:";
        cin>>opt;
        if(opt>4)
        break;
        if(opt==1)
        add();
        if(opt==2)
        mod();
        if(opt==3)
        del();
        if(opt==4)
        display();
    }
}



int main()
{
    EmpAMD k;
    k.menu();
    return 0;
}