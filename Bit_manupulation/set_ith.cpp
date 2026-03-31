#include<iostream>
using namespace std;

void ith_bit(int n,int i)
{
    int bitmask = 1 << i;
    
    cout<<(n | bitmask)<<endl;
    
}

int main() {
    int n = 6;
    int i;
    cin>>i;
    ith_bit(6,i);

    return 0;
}