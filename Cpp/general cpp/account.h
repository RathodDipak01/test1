class account
{
    private:
    int no;
    char nm[15];
    int bal;

    public:
    void setData();
    void display();
    int getNo()
    {
        return no;
    }
    char*getName()
    {
        return nm;
    }
    int getBalance()
    {
        return bal;
    }
};
void Account::setData()
{
    cout<<"\n Account no:";
    cin>>no;
    cout<<""
}