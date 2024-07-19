#include <iostream>
using namespace std;

# define N 5

class Array
{
    int x[N];
    public:
    Array();
    Array(int);
    Array(Array &);
    ~Array(){}

    friend istream & operator >> (istream &,Array &);
    friend ostream & operator << (ostream &,Array &);

    int total();
    double avg(){return double (total())/N;}
    int operator>(int a){return total()>a;}
    int operator<(int a){return total()<a;}
    int operator > (Array &t){return total()>t.total();}
    int operator < (Array &t){return total()<t.total();}

    int total() const;

    void operator-();
};



istream & operator >> (istream & in, Array & k)
{
    int i=0;
    while(i<N)
    {
        cout<<"\n Data: ";
        in>>k.x[i];
        i++;
    }
    return in;
}

ostream & operator << (ostream & out, Array & k)
{
    int i=0;
    out<<"\n Data: ";
    while(i<N)
    {
        out<<k.x[i]<<" ";
        i++;
    }
    return out;
}


Array::Array()
{
    for(int i=0; i<N; i++)
    x[i]=0;
}

Array::Array(int z)
{
    for (int i=0; i<N; i++)
    x[i]=z;
}

Array::Array(Array & k)
{
    for(int i=0; i<N; i++)
    x[i]=k.x[i];
}


void Array::operator-()
{
    int i=0,j=N-1,tmp;
    while(i<j)
    {
        tmp=x[i];
        x[i]=x[j];
        x[j]=tmp;
        i++;
        j--;
    }
}

int Array::total()
{
    int tot=x[0],i=1;
    while(i<N)
    tot+=x[i++];
    return tot;
}

int main()
{
    Array p;
    cin>>p;
    cout<<p;

    if(p>80)
    cout<<"\n Pass";

    else
    cout<<"\n Repeat";

    Array q;
    cin>>q;
    cout<<q;
    -q;
    cout<<q;

    if(p<q)
    cout<<"\n Total:"<<p.total();

    else
    cout<<"\n Total:"<<q.total();


}