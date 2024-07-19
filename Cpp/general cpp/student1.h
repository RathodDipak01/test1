class student1
{
    int rno;
    char nm[15];
    double mrk;
    public:
    void setData(int a)
    {
        rno=a;
        cout<<"\n Name:";
        cin>>nm;
        cout<<"\n Marks;";
        cin>>mrk;
    }
    void setData()
    {
        cout<<"\n Roll No";
        cin>>rno;
        cout<<"\n Name";
        cin>>nm;
        cout<<"\n Marks";
        cin>>mrk;
        void setMarks(double a)
        {
            mrk=a;
        }
        int getNo(){return rno;}
        char*getName(){return nm;}
        double get marks(){
            return mrk;
        }
        void display()
        {
            cout<<"\nRollno:"<<rno<<"\nName:"<<nm<<"\nMarks:"<<mrk;
        }
    }
};