#include<iostream>
using namespace std;

void odd_even(int n)
{
    if(!(n & 1))
    {
        cout<<"EVEN"<<endl;
    }
    else{
        cout<<"ODD"<<endl;
    }
}

int main() {

    odd_even(5);
    odd_even(8);
    return 0;
}