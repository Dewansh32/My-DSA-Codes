#include<iostream>
using namespace std;

int binary_search(int arr[],int n,int key)
{
    int st=0,end=n-1;
    while(st<=end)
    {
        int mid = (st + end)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid]<key) st = mid+1;
        else end = mid-1;
    }
    return -1;
}

int main() {
    int arr[] = {2,4,6,8,10,12,14,16};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout<<"Enter key to find: ";
    cin>>key;

    int index = binary_search(arr,n,key);
    
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(index == -1) cout<<"Key not found";
    cout<<key<<" is present at "<<index+1<<" position";

    return 0;
}