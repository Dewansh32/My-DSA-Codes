#include<iostream>
using namespace std;

void fast_expo(int x,int n)
{
    int ans = 1;

    while(n>0)
    {
        int lastdg = n & 1;
        if(lastdg == 1)
        {
            ans *= x;
        }

        x *= x;
        n = n >> 1;
    }

    cout<<ans<<endl;;
}

int main() {
    int x = 3;
    int p = 5;

    fast_expo(x,p);

    return 0;
}