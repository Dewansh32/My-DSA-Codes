#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int si,int ei,int mid)
{
    vector<int> temp;

    int i = si;
    int j = mid + 1;

    while(i<=mid && j<=ei)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        } 
        else{
            temp.push_back(arr[j]);
            j++;
        } 
    }


    while(i<=mid) 
    {
        temp.push_back(arr[i++]);
    }

    while(j<=ei)
    {
        temp.push_back(arr[j++]);
    }

    for(int idx = si,x=0;idx<=ei;idx++)
    {
        arr[idx] = temp[x++];
    }
}

void merge_sort(vector<int> &arr,int si,int ei)
{

    if(si >= ei) return;
    int mid = (si + ei)/2;

    merge_sort(arr,si,mid);
    merge_sort(arr,mid+1,ei);

    merge(arr,si,ei,mid);
    

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
    merge_sort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}