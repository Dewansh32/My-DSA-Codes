#include<iostream>
using namespace std;

void clear_i_bits(int n,int i)
{
    int temp = ~0;
    int bitmask = temp<<i;

    cout<<(n & bitmask);
    
}

int main() {
    clear_i_bits(15,2);

    return 0;
}