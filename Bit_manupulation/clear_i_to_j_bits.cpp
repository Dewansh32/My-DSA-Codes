#include<iostream>
using namespace std;

void clear_i_to_j(int n,int i,int j)
{
    // int bitmask = ~(1 << i);

    // for(int k=i+1;k<=j;k++)
    // {
    //     bitmask = bitmask & ~(1<<k);
    // }

    // n = n & bitmask;

    // cout<< n;

    int a = (~0) << (j + 1); // 1s before j
    int b = (1 << i) - 1;    // 1s after i
    int bitmask = a | b;     // combine to get 1s everywhere except between i and j
    
    n = n & bitmask;         // clear bits i to j
    cout << n;
    
}

int main() {
    clear_i_to_j(31,1,3);

    return 0;
}