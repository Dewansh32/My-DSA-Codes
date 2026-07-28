#include<bits/stdc++.h>
using namespace std;

bool reverse_num(int x)
{
    int a=0;
    int b=x;
    while(x>0)
    {
        int temp = x%10;
        a  = a*10 + temp;
        x = x/10;
    }
    
    return b*4 == a;
}

int main()
{
    for(int i=10000;i<=99999;i++)
    {
        if(reverse_num(i)) cout<<i<<endl;
    }
}