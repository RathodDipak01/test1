#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE;


NODE * createNode( int d)
{
    NODE *b;
    b = (NODE*) malloc(sizeof(NODE));
    b->data = d;
    b->next = NULL;
    return b;
}

NODE * getLastNode(NODE **a)
{
    NODE *b = *a;
    while(b->next!=NULL)
        b=b->next;
    return b;
}

void addB(NODE**a,int d)
{
    NODE *b = createNode(d);
    b->next= *a;
    *a = b;
}

void addE(NODE**a,int d)
{
    NODE *b, *c;
    if(*a == NULL)
        *a = createNode(d);
    else
    {
        b = createNode(d);
        c = getLastNode(a);
        c->next = b;
    }
}

void display(NODE **a)
{
    NODE *b = *a;
    if(*a == NULL)
        printf("\n List is empty");
    else
    {
        printf("\n Data: \n");
        while(b!=NULL)
        {
            printf("%4d",b->data);
            b=b->next;
        }
    }
    return ;
}

int sum(NODE**a)
{
    int tot=0;
    NODE *b = *a;
    while(b!=NULL)
    {
        tot = tot+b->data;
        b=b->next;
    }
    return tot;
}


void main()
{
    NODE *p = NULL; //Header pointer to List
    addE(&p,10);
    addE(&p,20);
    addE(&p,30);
    addB(&p,1);
    display(&p);
    printf("\n Sum: ");
    printf("%4d",sum(&p));
    return ;
}