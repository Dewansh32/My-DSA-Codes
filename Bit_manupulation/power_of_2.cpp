#include<iostream>
using namespace std;

void power_of_2(int n)
{
    if(!(n & (n-1))) cout<<"Power of 2"<<endl;
    else cout<<"No power of 2";
}

int main() {
    int n;
    cin>>n;

    power_of_2(n);

    return 0;
}