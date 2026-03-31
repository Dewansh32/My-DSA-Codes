#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int si,int ei)
{
    int pvt = arr[ei];
    int i = si-1;

    for(int j = si;j<ei;j++)
    {
        if(arr[j]<=pvt)
        {
            swap(arr[++i],arr[j]);
        }
    }

    swap(arr[++i],arr[ei]);
    return i;
}

void quick_sort(vector<int> &arr,int si,int ei)
{
    if(si>=ei) return;

    int pvtIdx = partition(arr,si,ei);
    quick_sort(arr,si,pvtIdx-1);
    quick_sort(arr,pvtIdx+1,ei);
}

void printArray(vector<int> &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {
    vector<int> arr = {6,3,7,5,4,2};
    int n = arr.size();
    quick_sort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}