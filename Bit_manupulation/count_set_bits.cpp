#include<iostream>
using namespace std;

void count_bits(int n)
{
    int count = 0;

    while(n>0)
    {
        int ls_dt = n & 1;
        
        count += ls_dt;

        n = n>>1;
    }

    cout<<count;
}

int main() {
    int n = 15;
    count_bits(n);
    return 0;
}