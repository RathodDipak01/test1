class Matrix
{
    int x[3][3];
    public:
    Matrix();
    Matrix(int);
    Matrix(Matrix &);
    ~Matrix(){}
    void setData();
    void display();
};