
class Martix1
{
    int x[3][3];
    public:
    void init();
    void setData();
    void display();
    void transpose();
};

void Matrix1::init()
{
    int i,j;
    for(i,j);
    for(i=0;i<3;j++)
    {
        for(j=0;j<3;j++)
        x[i][j]=0;
    }
}

void Matrix1::setData()
{
    int i,j;
    cout<<"\n Data \n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        cin>>x[i][j];
    }
}

void Matrix1::display()
{
    int i,j;
    cout <<"\n Matrix \n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        cout<<setw(5)<<x[i][j];
        cout<<"\n";
    }
}

void Matrix1::transpose()
{
    int i,j,tmp;
    for(i=0;i<3;i++)
    {
        for(j=0;j<i;j++)
       {
        tmp=x[i][j];
        x[i][j]=x[j][i];
        x[j][i]=tmp;
       }
    }
}

void main()
{
    Matrix1 a;
    a.setData();
    a.display();
    a.transpose();
    a.display();
}