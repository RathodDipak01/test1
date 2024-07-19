

class MyData
{
    int x[5]
    public:
    void init();
    void setData();
    void display();
    int total();
    int avg()
    {
        return total()/5;
    }
}

int findMax();
int findMin();
int findMaxPos();
int findMinPos();
int isOrdered();
int sserach(int sv);
int bsearch(int sv);

void set(int d,int pos)
{
    x[pos]=d;
}
int get(int pos)
{
    return x[pos];
}

void MyData::init()
{
    for(int i=0;i<5;i++)
    x[i]=0;
}
void MyData::setData()
{
    for(int i=0;i<5;i++)
    {
        cout<<"\nData:";
        cin>>x[i];
    }
}
void MyData::display()
{
    cout<<"\nData\n";
    for(int i=0;i<5;i++)
    cout<<setw(5)<<x[i];
}

int MyData::total()
{
    int tot=x[0],i=1;
    while(i<5)
    tot+=x[i++];
    return tot;
}

int MyData::findMax()
{
    int pos=0,i=1;
    while(i<5)
    {
        if(x[i]>x[pos])
        pos=i;
        i++;
    }
    return x[pos];
}

int MyData::findMaxPos()
{
    int pos=0,i=1;
    while(i<5)
    {
        if(x[i]<x[pos])
        pos=i;
        i++;
    }
    return pos;
}

int MyData::findMin()
{
    int pos=0,i=1;
    while(i<5)
    {
        if(x[i]>x[pos])
        pos=i;
        i++;
    }
    return x[pos];
}

int MyData::findMinPos()
{
    int pos=0,i=1;
    while(i<5)
    {
        if(x[i]<x[pos])
        pos=i;
        i++;
    }
    return pos;
}

int MyData::isOrdered()
{
    for(int i=1;i<5;i++)
    {
        if(x[i]<x[i-1])
        break;
    }
    return (i==5);
}

int MyData::ssearch(int sv)
{
    int i=0;
    while(i<5)
    {
        if(x[i]==sv)
        break;
        i++;
    }
    return(i==5)!0:1;
}

int MyData::bsearch(int sv)
{
    int l=0,r=4,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(x[mid]==sv)
        break;
        if(sv<x[mid])
        r=mid-1;
        elsel=mid+1;
    }
    return (l<=r)?1:0;
    }


