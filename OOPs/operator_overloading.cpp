#include<iostream>
using namespace std;

class complex{
    int real;
    int img;
    public:

    complex(int r,int i)
    {
        real = r;
        img = i;
    }

    void shownum()
    {
        cout<<real<<" + "<<img<<"i\n";
    }

    void operator +(complex &obj)
    {
        int newReal =  this->real + obj.real;
        int newImg = this->img + obj.img;
        complex c3(newReal,newImg);
        c3.shownum();
    }
}; 

int main() {
    complex c1(1,2);
    complex c2(3,4);

    c1.shownum();
    c2.shownum();

    c1 + c2;

    return 0;
}