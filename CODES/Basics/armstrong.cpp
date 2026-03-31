#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int num = n;

    int sum = 0;

    while(n>0)
    {
        int ls_dg = n%10;
        sum += ls_dg*ls_dg*ls_dg;
        n = n/10;
    }
    
    if(sum == num) cout<<num<<" is armstrong number"<<endl;
    else cout<<num<<" is not armstromg";

    return 0;
}