#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int no;
    char nm[15];
    int mrk;
} STU;

typedef struct node
{
    STU data;
    struct node *next;
} NODE;

typedef struct stulist
{
    NODE *st;
} STULIST;

void input(STU *a, int n)
{
    a->no = n;
    printf("\nName:");
    scanf("%s", a->nm);
    printf("\n Marks:");
    scanf("%d", &a->mrk);
}

void display(STU *a)
{
    printf("\n %5d %-15s %4d ", a->no, a->nm, a->mrk);
}

// function to search
NODE*search(STULIST*t,int n)
{
    NODE*a=t->st;
    while(a!=NULL)
    {
        if((a->data).no==n)
        break;
        a=a->next;
    }
    return a;
}

//function to search name
NODE* searchNm(STULIST *t, char *b)
{
    NODE *a = t->st;
    while (a != NULL)
    {
        if (strcmp((a->data).nm, b) == 0)
            break;
        a = a->next;
    }
    return a;
};


void add(STULIST*t)
{
    int no;
    NODE *a;
    printf("\n Roll No: ");
    scanf("%d",&no);
    a=search(t,no);
    if(a!=NULL)
    {
        printf("\n Record Exists:");
        return;
    }
    a=(NODE*)malloc(sizeof(NODE));
    input(&a->data,no);
    a->next=t->st;
    t->st=a;
}


void mod(STULIST*t)
{
    int no;
    NODE *a;
    printf("\n Roll No: ");
    scanf("%d",&no);
    a=search(t,no);
    if(a==NULL)
    {
        printf("\n Record NOT Exists:");
        return;
    }
    input(&a->data,no);
}


void del(STULIST*t)
{
    int no;
    NODE *a,*b;
    printf("\n Roll No: ");
    scanf("%d",&no);
    a=search(t,no);
    if(a==NULL)
    {
        printf("\n Record Not Exists:");
        return;
    }

    if(a==t->st)   //first node
    t->st=a->next;
    else
    {
        b=t->st;
        while(b->next!=a)
        b=b->next;
        b->next=a->next;
    }
    free(a);
}


//function to display list data 
void displayall(STULIST *t) {
    NODE *a = t->st;
    if (t->st == NULL) {
        printf("The list is empty.\n");
        
    }
    else
    {
        printf("\n Student Data:\n");
        while(a!=NULL){
            display(&a->data);
            a=a->next;
        }
    }
    
    }


    int main()
    {
        STULIST p;
        p.st=NULL;
        add(&p);
        add(&p);
        add(&p);
        add(&p);
        displayall(&p);
        mod(&p);
        displayall(&p);
        add(&p);
        displayall(&p);
        del(&p);
        displayall(&p);
        
    }