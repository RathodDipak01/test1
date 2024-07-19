
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
} NODE;


typedef struct singlelist
{
    NODE*st;      //head node pointer
    int cnt;      //count of Nodes
}SLIST;


void init(SLIST *t)
{
    t->st=NULL;
    t->cnt=0;
}


//function to create node
NODE*createNode(int d)
{
    NODE*a;
    a=(NODE*)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}


//function to get last node
NODE*getlastnode(NODE*a)
{
    while(a->next!=NULL)
    a=a->next;
    return a;
}


//function to add node at end
void addE(SLIST*t,int d)
{
    NODE*a=createNode(d);
    NODE*b;
    if(t->st==NULL)
    t->st=a;
    else
    {
        b=getlastnode(t->st);
        b->next=a;
    }
    t->cnt++;
}


//function to add node at begin
void addB(SLIST*t,int d)
{
    NODE *a=createNode(d);
    a->next=t->st;
    t->st=a;
    t->cnt++;
}


// function to display list data
void display(SLIST*t)
{
    NODE*a=t->st;
    if(t->cnt==0)
    printf("\n Empty List");
    else
    {
        printf("\nData\n");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}


//function to compute Sum
int sum(SLIST*t)
{
    NODE*a=t->st;
    int total=0;
    while(a!=NULL)
    {
        total+=a->data;
        a=a->next;
    }
    return total;
}


//function to count NODE having odd data
int oconut(SLIST *t)
{
    int tot=0;
    NODE *a=t->st;
    while(a!=NULL)
    {
        tot+=(a->data%2);
        a=a->next;
    }
    return tot;
}


//function to count NODE with even data
int econut(SLIST *t)
{
    int tot=0;
    NODE *a=t->st;
    while(a!=NULL)
    {
        tot+=(a->data%2==0);
        a=a->next;
    }
    return tot;

    // return t->cnt-ocount(t);
}


//function to sum even data NODES
int esum(SLIST*t)
{
    int tot=0;
    NODE*a=t->st;
    while(a!=NULL)
    {
        if(a->data%2==0)
        tot+=a->data;
        a=a->next;
    }
    return tot;
}


//function to sum odd data NODES
int osum(SLIST*t)
{
    int tot=0;
    NODE*a=t->st;
    while(a!=NULL)
    {
        if(a->data%2==1)
        tot+=a->data;
        a=a->next;
    }
    return tot;
}


//function to delete first node
void delFirst(SLIST*t)
{
    NODE*a=t->st;
    if(t->st==NULL)
    return ;
    t->st=a->next;
    t->cnt--;
    free(a);
}


//function to delete last node 
void delLast(SLIST* t)
 {
    NODE*a=t->st,*b;
    if (t->st == NULL) 
        return;

    if(t->cnt==1) // only one node
    t->st=NULL;
    else{
        while(a->next!=NULL)
        {
            b=a;
            a=a->next;
        }
        b->next=NULL;
    } 
t->cnt--;
 }


//function to delete ith node on list 
void deliNode(SLIST*t,int pos)
{
    int i=1;
    NODE *a,*b,*c;
    if(t->st==NULL||pos<1||pos>t->cnt)
    return;
    if(pos==1)
    delFirst(t);
    else
    {
        if(pos==t->cnt)
        delLast(t);
        else
        {
            a=t->st;
            while(i<pos)
            {
                b=a;
                a=a->next;
                i++;
            }
            c=a->next;
            b->next=c;
            t->cnt--;
        }
    }
}