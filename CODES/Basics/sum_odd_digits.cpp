#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int sum = 0;

    while(n>0)
    {
        int ls_dg = n%10;
        if(ls_dg%2 != 0)
        {
             sum += ls_dg;
        }
        n = n/10;
    }

    cout<<"Sum of digits: "<<sum<<endl;

    return 0;
}