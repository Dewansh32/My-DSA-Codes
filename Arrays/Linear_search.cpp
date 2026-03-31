#include<iostream>
using namespace std;

int linear_search(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(key == arr[i]) return i;
    }
    return -1;
}

int main() {
    int arr[] = {15, 42, 8, 73, 29, 56, 91, 34, 67, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout<<"Enter key to find: ";
    cin>>key;

    int index = linear_search(arr,n,key);
    
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(index == -1) cout<<"Key not found";
    cout<<key<<" is present at "<<index+1<<" position";

    return 0;
}