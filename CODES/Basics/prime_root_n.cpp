#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool prime = true;
    for(int i=2;i<sqrt(n);i++) // After root of n factors repeat so no need to check after that
    {
        if(n%i == 0) prime = false;
    }
    if(prime) cout<<"n is prime";
    else cout<<"n is not prime";

    return 0;
}