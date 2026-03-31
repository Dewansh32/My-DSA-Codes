#include<iostream>
using namespace std;

void ith_bit(int n,int i)
{
    int bitmask = 1 << i;
    
    if(!(n & bitmask))
    {
        cout<<"0"<<endl;
    }
    else{
        cout<<"1";
    }
    
}

int main() {
    int n = 6;
    int i;
    cin>>i;
    ith_bit(6,i);

    return 0;
}