#include<iostream>
using namespace std;

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int minidx = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[minidx]>arr[j])
            {
                minidx = j;
            }
        }
        if(minidx != i)
        {
            swap(arr[i],arr[minidx]);
        }
   }
}

int main() {
    int arr[5] = { 5,4,1,3,2};
    int n = 5;
    selection_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}