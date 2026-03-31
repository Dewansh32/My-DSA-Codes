#include<iostream>
using namespace std;

void update_ith_bit(int n,int i,int val)
{
    n = n & ~(1<<i);
    
    if(val == 1) n = n | (1<<i);

    cout<<n;
    
}

int main() {
    update_ith_bit(7,3,1);

    return 0;
}