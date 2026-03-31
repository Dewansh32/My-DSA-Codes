#include<iostream>
using namespace std;

class base{
    public:

    virtual void hello()
    {
        cout<<"Parent hello\n";
    }
};

class child: public base{
    public:

    void hello()
    {
        cout<<"child hello\n";
    }
};

int main() {
    child c1;
    base *ptr;

    ptr = &c1;
    ptr->hello();
    
    return 0;
}