class number
{
    int x;
    int y;
    void swap()
    {
        int z=x;
        x=y;
        y=z;
    }
    public:
    void setData(int a)
    {
        x=y=a;
    }
    void setData(int x,int y)
    {
       
    }

}

cpp uses a unique keyword called this to represent an object than infolks a member function 
this is a pointer that points to the object for which this function was called for exxample a function call a.setData[10,15]
will set the pointer this to the address of the object a the starting address is the same as the address of the first variable in the class structure
This unique pointer is atotamically passed to a memember function when it is called the pointer this acts as an implecent argument to all the member functions
function with class object as argument