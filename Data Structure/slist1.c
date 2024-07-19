#include<stdio.h>
#include"slist.h"

void main()
{
    SLIST p;
    init(&p);
    addB(&p,10);
    addE(&p,20);
    addE(&p,30);
    addE(&p,40);
    dispaly(&p);
    printf("\n Sum:%d",sum(&p));




    delFirst(&p);
    delLast(&p);

    return;
}
