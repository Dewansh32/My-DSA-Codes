#include<iostream>
using namespace std;

// void reverse_using_space(int arr[],int n)
// {
//     int copy[n];

//     for(int i=0;i<n;i++)
//     {
//         copy[i] = arr[n-i-1];
//     }

//     for(int i=0;i<n;i++)
//     {
//         arr[i] = copy[i];
//     }

// }

void reverse_without_space(int arr[],int n)
{
    int start = 0;
    int end = n - 1;
    
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int arr[5] = {5,4,3,9,2};
    int n=5;

    // reverse_using_space(arr,n);
    reverse_without_space(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}