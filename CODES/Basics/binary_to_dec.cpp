#include<iostream>
using namespace std;

void binToDec(int n)
{
    
    int decNum = 0;
    int pow = 1;
    
    while(n>0)
    {
        int ls_dg = n%10;
        decNum += ls_dg*pow;
        pow = pow*2;
        n = n/10;
    }

    cout<<decNum;
}

int main()
{
    int n;
    cin>>n;
    binToDec(n);
}