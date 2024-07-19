#include <iostream>
using namespace std;

#define N 5

class Array {
    int x[N];
public:
    Array();
    Array(const Array &);
    ~Array() {}

    friend istream &operator>>(istream &, Array &);
    friend ostream &operator<<(ostream &, const Array &);

    int total() const;
    operator int() const {
        return total();
    }
    operator double() const {
        int tot = *this;
        return (double)tot / N;
    }

    void operator-();
};

istream &operator>>(istream &in, Array &k) {
    for (int i = 0; i < N; ++i) {
        cout << "\n Data: ";
        in >> k.x[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const Array &k) {
    out << "\n Data: ";
    for (int i = 0; i < N; ++i) {
        out << k.x[i] << " ";
    }
    return out;
}

Array::Array() {
    for (int i = 0; i < N; ++i)
        x[i] = 0;
}

Array::Array(const Array &k) {
    for (int i = 0; i < N; ++i)
        x[i] = k.x[i];
}

void Array::operator-() {
    int i = 0, j = N - 1, tmp;
    while (i < j) {
        tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;
        i++;
        j--;
    }
}

int Array::total() const {
    int tot = x[0];
    for (int i = 1; i < N; ++i)
        tot += x[i];
    return tot;
}

int main() {
    Array p;
    cin >> p;
    cout << p;

    if (p > 80)
        cout << "\n Pass";
    else
        cout << "\n Repeat";

    Array q;
    cin >> q;
    cout << q;
    -q;
    cout << q;

    if (p < q)
        cout << "\n Total: " << p.total();
    else
        cout << "\n Total: " << q.total();

    return 0;
}
