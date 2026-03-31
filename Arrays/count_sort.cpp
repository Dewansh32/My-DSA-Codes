#include<iostream>
using namespace std;

void count_sort(int arr[],int n)
{
    int freq[10000];
    int minval = INT32_MAX,maxval = INT32_MIN;

    for(int i=0;i<n;i++)
    {
        minval = min(minval,arr[i]);
        maxval = max(maxval,arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }

    for(int i=minval,j=0;i<=maxval;i++)
    {
        while(freq[i]>0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }
}

int main() {
    int arr[8] = {1,4,1,3,2,4,3,7};
    int n=8;

    count_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}