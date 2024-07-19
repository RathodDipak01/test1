#include <iostream>
using namespace std;

class Number
{
    int no;
public:
    Number() {
        no = 0;
        cout << "\nDefault";
    }

    Number(int a) {
        no = a;
        cout << "\nPara";
    }

    Number(const Number &t) {
        no = t.no;
        cout << "\nCopy";
    }

    ~Number() {
        cout << "\nDestructor";
    }

    void setData(int a) {
        no = a;
    }

    void setData() {
        cout << "\nNo: ";
        cin >> no;
    }

    void display() const {
        cout << "\nNo: " << no;
    }

    int getNo() const {
        return no;
    }
};

int main() {
    Number a;
    a.display();

    {
        Number b(13);
        b.display();
        Number c(10);  
        c.display();
        c.setData();
        c.display();
    }

    a.setData();
    a.display();

    Number d(a);
    d.display();

    return 0;
}
