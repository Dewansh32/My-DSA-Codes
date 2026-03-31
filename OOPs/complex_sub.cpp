#include<iostream>
using namespace std;

class complex{
    public:
    int real;
    int img;

    complex(int r,int i)
    {
        real = r;
        img = i;
    }

    void print()
    {
        cout<<real<<" + "<<img<<"i"<<endl;
    }


    void operator -(complex &c2)
    {
        int resreal = this->real - c2.real;
        int resimg = this->img - c2.img;
        complex c3(resreal,resimg);
        cout<<"result: ";
        c3.print();
    }
};

int main() {
    complex c1(3,4);
    complex c2(1,2);

    c1 - c2;
    return 0;
}