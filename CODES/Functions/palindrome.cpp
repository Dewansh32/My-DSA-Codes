#include<iostream>
using namespace std;

void isPalindrome(int n)
{
    int num = n;
    int reverse = 0;
    while(n>0)
    {
        int ls_dg = n%10;
        reverse = reverse*10 + ls_dg;
        n = n/10;
    }

    if(num == reverse) cout<<"TRUE";
    else cout<<"False";
}

int main() {
    int n;
    cin>>n;

    isPalindrome(n);
    return 0;
}