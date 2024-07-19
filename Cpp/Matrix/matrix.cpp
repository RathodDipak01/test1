#include <iostream>
using namespace std;



class Matrix {
    int x[3][3];
public:
    Matrix();
    Matrix(int);
    Matrix(const Matrix &);
    ~Matrix() {}

    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, Matrix &);

    Matrix operator+(const Matrix &) const;
    Matrix operator-(const Matrix &) const;
    Matrix operator*(const Matrix &) const;
    Matrix transpose() const;
};

Matrix::Matrix() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            x[i][j] = 0;
        }
    }
}

Matrix::Matrix(int val) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            x[i][j] = val;
        }
    }
}

Matrix::Matrix(const Matrix &m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            x[i][j] = m.x[i][j];
        }
    }
}

istream &operator>>(istream &input, Matrix &m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "\n Data: ";
            input >> m.x[i][j];
        }
    }
    return input;
}

ostream &operator<<(ostream &output, Matrix &m) {
    for (int i = 0; i < 3; ++i) {
        output << "\n Data: ";
        for (int j = 0; j < 3; ++j) {
            output << m.x[i][j] << " ";
        }
    }
    return output;
}

Matrix Matrix::operator+(const Matrix &m) const {
    Matrix result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.x[i][j] = x[i][j] + m.x[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &m) const {
    Matrix result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.x[i][j] = x[i][j] - m.x[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &m) const {
    Matrix p;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            p.x[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                p.x[i][j] += x[i][k] * m.x[k][j];
            }
        }
    }
    return p;
}

Matrix Matrix::transpose() const {
    Matrix result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.x[j][i] = x[i][j];
        }
    }
    return result;
}

int main() {
    Matrix p, q;

    cout << "matrix 1:\n";
    cin >> p;
    cout << "matrix 2:\n";
    cin >> q;

    cout << "Matrix 1:\n" << p;
    cout << "\n Matrix 2:\n" << q;

    Matrix sum = p + q;
    cout << "\n Sum:\n" << sum;

    Matrix diff = p - q;
    cout << "\n Difference:\n" << diff;

    Matrix product = p * q;
    cout << "\n Product:\n" << product;

    Matrix transpose1 = p.transpose();
    cout << "\n Transpose1:\n" << transpose1;

    Matrix transpose2 = q.transpose();
    cout << "\n Transpose2 :\n" << transpose2;

    return 0;
}
