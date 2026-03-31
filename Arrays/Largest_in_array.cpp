#include<iostream>
using namespace std;

int main() {
    int arr[] = {15, 42, 8, 73, 29, 56, 91, 34, 67, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    cout << "Max element in array: " << max << endl;
    return 0;
}