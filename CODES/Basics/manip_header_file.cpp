#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float PI = 3.14159265359;
    double PI2 = 3.14159265359;

    cout<<setprecision(12)<<"PI = "<<PI<<endl;
    cout<<setprecision(12)<<"PI2 = "<<PI2<<endl;// we can use setprecision because of iomanip header file

    return 0;
}