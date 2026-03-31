#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char arr[] = "racecar";
    int n = strlen(arr);

    int st = 0;
    int end = n-1;

    bool palindrome = true;

    while(st<end)
    {
        if(arr[st] != arr[end]) palindrome = false;
        st++;
        end--;
    }

    if(palindrome) cout<<"The word is palindrome";
    else cout<<"Not palindrome";
    return 0;
}
