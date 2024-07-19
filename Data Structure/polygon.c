#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coe;
    int man;
    struct node * next;
}NODE;
typedef struct poly
{NODE * st;}POLY;

void init(POLY *t)
{
    t->st = NULL;
}

NODE * createNode(int c, int m)
{
    NODE * a =(NODE *)malloc(sizeof(NODE));
    a->coe = c;
    a->man = m;
    a->next = NULL;
    return a;
}

void delPoly(POLY * t)
{
    NODE *a = t->st;
    while(t->st != NULL)
    {
        t->st = a->next;
        free(a);
        a = t->st;
    }
}

void createPoly(POLY * t)
{
    int c, m;
    NODE *a, *b;
    if(t->st != NULL)
        delPoly(t);
    while(1)
    {
        printf("\n coe Man \n");
        scanf("%d %d",&c,&m);
        if(c == 0 && m == 0)
            break;
        if(m < 0)
        {
            printf("Negative exponent not allowed.\n");
            continue;
        }
        if(t -> st == NULL)
            t -> st = a = createNode(c,m);
        else
        {
            if(m >= b ->man)
            {
                printf("\nInvalid term. Exponents should be in descending order.\n");
                continue;
            }
            a = createNode(c,m);
            b -> next = a;
        }
        b = a;
    }
}

void displayPoly(POLY * t)
{
    NODE *a = t->st;
    if(t->st == NULL)
    {
        printf("\n Empty List");
        return;
    }
    printf("\n");
    while(a!= NULL)
    {
        if(a->coe > 0)
            printf("+");
        printf("%d^%d ",a->coe,a->man);
        a = a->next;
    }
}

POLY add(POLY * x, POLY *y)
{
    POLY w ;
    int c, m;
    NODE *p = x->st, *q = y->st;
    NODE *r,*s;
    init(&w);
    while(p && q)
    {
        if(p->man == q->man)
        {
            c = p ->coe + q->coe;
            m = p->man;
            p = p->next;
            q = q->next;
        }
        else
        {
            if(p->man > q->man)
            {
                c = p->coe;
                m = p->man;
                p = p->next;
            }
            else{
                c = q -> coe;
                m = q ->man;
                q = q->next;
            }
        }
        r = createNode(c,m);
        if(w.st == NULL)
            w.st = r;
        else
            s -> next = r;
        s = r;
    }
    while(p)
    {
        c = p->coe;
        m = p->man;
        s->next = createNode(c,m);
        s = s->next;
        p = p->next;
    }
    while(q)
    {
        c = q->coe ;
        m = q->man;
        s->next = createNode(c,m);
        s = s->next;
        q = q->next;
    }
    return w;
}

POLY sub (POLY *x, POLY *y)
{
    POLY w ;
    int c, m;
    NODE *p = x->st, *q = y->st;
    NODE *r,*s;
    init(&w);
    while(p && q)
    {
        if(p->man == q->man)
        {
            c = p ->coe - q->coe;
            m = p->man;
            p = p->next;
            q = q->next;
        }
        else
        {
            if(p->man > q->man)
            {
                c = p->coe;
                m = p->man;
                p = p->next;
            }
            else{
                c = -q -> coe;
                m = q ->man;
                q = q->next;
            }
        }
        r = createNode(c,m);
        if(w.st == NULL)
            w.st = r;
        else
            s -> next = r;
        s = r;
    }
    while(p)
    {
        c = p->coe;
        m = p->man;
        s->next = createNode(c,m);
        s = s->next;
        p = p->next;
    }
    while(q)
    {
        c = -q->coe ;
        m = q->man;
        s->next = createNode(c,m);
        s = s->next;
        q = q->next;
    }
    return w;   
}

int main()
{
        POLY p,q,r;
        init(&p);
        init(&q);
        init(&r);
        createPoly(&p);
        displayPoly(&p);
        createPoly(&q);
        displayPoly(&q);
        r = add(&p,&q);
        displayPoly(&r);
        delPoly(&r);
        r = sub(&p,&q);
        displayPoly(&r);
        delPoly(&p);
        delPoly(&q);
        delPoly(&r);
}