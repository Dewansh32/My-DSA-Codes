#include<bits/stdc++.h>
using namespace std;

void heapify(int i,vector<int> &arr,int n)
{
    int maxidx = i;
    int c1 = i*2 + 1;
    int c2 = i*2 + 2;

    if(arr[c1] > arr[maxidx] && c1<n)
    {
        maxidx  = c1;
    }
    if(arr[c2] > arr[maxidx] && c2<n)
    {
        maxidx  = c2;
    }

    if(maxidx != i)
    {
        swap(arr[maxidx],arr[i]);
        heapify(maxidx, arr, n);
    }
}

void heap_sort(vector<int> arr)
{
    int n = arr.size();

    for(int i=n/2-1;i>=0;i--)
    {
        heapify(i,arr,n);
    }

    for(int i=0;i<n-1;i++)
    {
        swap(arr[0],arr[n-i-1]);
        heapify(0,arr,n-i-1);
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main() {
    vector<int> arr = {1,4,2,5,3};

    heap_sort(arr);
    return 0;
}