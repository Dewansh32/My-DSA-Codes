#include<iostream>
using namespace std;

int pow(int x,int n)
{
    if(n ==0) return 1;

    int halfpow = pow(x,n/2);
    int halfpowsq = halfpow * halfpow;

    if(n%2 != 0)
    {
        return x * halfpowsq;
    }

    return halfpowsq;
}

int main() {
    
    cout<<pow(2,10);
    return 0;
}