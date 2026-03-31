#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];  // Store the current element
        int j = i - 1;     // Start from previous element
        
        // Move elements greater than key one position ahead
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;  // Place key in correct position
    }
}

int main() {
    int arr[5] = { 5,4,1,3,2};
    int n = 5;
    insertion_sort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}