#include"MyTime.h"
int main()
{
    MyTime a(5,29);
    MyTime b,c;
    a.display();
    b.display();
    b.setTime();
    b.display();
    c=a.add(b);
    c.display();

    return 0;
    
}