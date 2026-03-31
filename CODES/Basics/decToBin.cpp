#include<iostream>
using namespace std;

void decToBin(int n)
{
    int pow = 1;
    int decNum = 0;

    while(n>0)
    {
        int rem = n%2;
        decNum += rem*pow;
        n = n/2;
        pow = pow*10;
    }

    cout<<decNum;
}

int main() {
    int n;
    cout<<"Enter number in decimal: ";
    cin>>n;

    decToBin(n);
    return 0;
}