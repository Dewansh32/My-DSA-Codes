#include<iostream>
using namespace std;

int first_occurence(int arr[],int i,int target,int n)
{
    if(i == -1) return -1;
    else if(arr[i] == target) return i;

    first_occurence(arr,i-1,target,n);
}

int main() {
    int arr[6] = {1,2,3,3,3,4};
    int n = 6;

    cout<<first_occurence(arr,n-1,3,n);
    return 0;
}