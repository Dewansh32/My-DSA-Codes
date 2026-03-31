#include<iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    while(n>1)
    {
        fact *= n;
        n--;
    }
    return fact;
}

int binomial_coff(int n,int r)
{
    int bc = factorial(n)/(factorial(r)*factorial(n-r));
    return bc;
}

int main() {
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    int r;
    cout<<"Enter value of r: ";
    cin>>r;

    int bc = binomial_coff(n,r);

    cout<<bc;
    return 0;
}