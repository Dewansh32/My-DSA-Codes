#include<iostream>
using namespace std;

int friend_pair(int n)
{
    if(n == 1 || n == 2) return n;

    int ans1 = friend_pair(n-1);
    int ans2 = (n-1) * friend_pair(n-2);

    return ans1 + ans2;
}

int main() {

    cout<<friend_pair(5);
    
    return 0;
}