#include<iostream>
using namespace std;

void print_subarray(int arr[], int n)
{
    cout << "🔢 All possible subarrays:\n";
    cout << "========================\n";
    
    for(int i = 0; i < n; i++)
    {   
        cout << "Starting from index " << i << ": ";
        for(int j = i; j < n; j++)  // Start from i, not n-1
        {
            cout << "[";
            for(int k = i; k <= j; k++)
            {
                cout << arr[k];
                if(k < j) cout << ", ";  // Add comma only between elements
            }
            cout << "] ";
        }
        cout << "\n";
    }
}

int main() {
    int arr[5] = {2, 10, 4, 3, 8};
    int n = 5;
    
    cout << "🎯 Original array: [";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n-1) cout << ", ";
    }
    cout << "]\n\n";

    print_subarray(arr, n);

    return 0;
}