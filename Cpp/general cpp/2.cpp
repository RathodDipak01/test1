#include<iostream>
#include"student1.h"
void main()
{
    student1 a[5];
    for(int i=0;i<5;i++)
    a[i].setData(i+1);
    for(i=0;i<5;i++)
    a[i].display();
    int cnt=0;
    for(i=0;i<5;i++)
    {
        if(a[i].getMarks()>9.2)
        cnt++;
    }
    cout<<"\ncount:"<<cnt;
}