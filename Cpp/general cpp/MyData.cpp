#include <iostream>
#include "array.h"
using namespace std;
void main()
{
    MyData p;
    p.init();
    p.display();
    p.setData();
    p.display();

    cout << "\n Total:" << p.total() << "\nAvg:" << p.avg();
    int pos = p.findMaxPos();
    count << "\n MaxDataPosition:" << pos << "\nManValue:" << p.get(pos);
    pos = p.findMinPos();
    count << "\n MinDataPosition:" << pos << "\nMinValue:" << p.get(pos);

    cout << "\n Enter search value:";
    int sv;
    cin > sv;
    
    if 
    (p.isOrdered() == 0)
        res = p.ssearch(sv);
    else
        res = p.bsearch(sv);

    if 
    (res == 0)
        cout << "\n NotFound";
    else
        cout << "\n Found";
    return;
}