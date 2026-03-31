#include<iostream>
using namespace std;

void trapped_water(int arr[],int n)
{
    if(n<3) return;

    int left_max[n];
    int right_max[n];

    left_max[0] = INT32_MIN;
    for(int i=1;i<n;i++)
    {
        left_max[i] = max(left_max[i-1],arr[i-1]);
    }
    right_max[n-1] = INT32_MIN;
    for(int i=n-2;i>=0;i--)
    {
        right_max[i] = max(right_max[i+1],arr[i+1]);
    }

    int total_water = 0;
    for(int i=0;i<n;i++)
    {
        int min_bar = min(left_max[i],right_max[i]);
        int quan = min_bar - arr[i];
        if(quan<0) continue;
        total_water += quan;
    }
    cout<<"Total water capacity: "<<total_water;
}

int main() {
    int arr[7] = {4,2,0,6,3,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    trapped_water(arr,n);
    
    return 0;
}