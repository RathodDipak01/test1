#include<stdio.h>
#include"slist.h"
void main()
{
    SLIST p;
    int pos,opt,res,d;
    init(&p);
    while(1)
    {
        printf("\n Menu \n 1.Add at end \n 2.Add at beg \n 3.Count \n 4.Display \n 5.Sum \n 6.Odd data sum /n 7.Even data sum /n 8.Odd data count /n 9.Even data count /n 10.Del first /n 11.Del last /n 12.Del ith node /n 13.Exit /n Option:");
        scanf("%d",&opt);
        if(opt>12)
        break;

        switch(opt)
    {
        case 1:
        printf("\n Add data at end:");
        scanf("%d",&d);
        addE(&p,d);
        break;

        case 2:
        printf("\n Add data at beg:");
        scanf("%d",&d);
        addB(&p,d);
        break;

        case 3:
        printf("\n Total Nodes:%d",p.cnt);
        break;

        case 4:
        display(&p);
        break;

        case 10:
        delFirst(&p);
        break;

        case 11:
        delLast(&p);
        break;

        case 12:
        printf("\n Node no to delete:");
        scanf("%d",&pos);
        deliNode(&p,pos);
        break;

        case 5:
        printf("\n Sum:%d",sum(&p));
        break;

         case 6:
        printf("\n OddDataSum:%d",osum(&p));
        break;

         case 7:
        printf("\n EvenDataSum:%d",esum(&p));
        break;

         case 8:
        printf("\n OddDataNodes:%d",ocount(&p));
        break;

         case 9:
        printf("\n EvenDataNodes:%d",ecount(&p));
        break;

       }
    }
}