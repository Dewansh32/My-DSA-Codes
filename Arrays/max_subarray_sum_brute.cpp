#include<iostream>
using namespace std;

void max_sum(int arr[],int n)
{
    int maxSum=INT32_MIN;
    for(int start = 0;start<n;start++)
    {
        for(int end = start;end<n;end++)
        {
            int currSum = 0;
            for(int k=start;k<=end;k++)
            {
                currSum += arr[k];
                
            }
            cout<<currSum<<" , ";
            maxSum = max(currSum, maxSum);
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Max Subarray Sum is: "<<maxSum;
}

void max_sum2(int arr[],int n)
{
    int maxSum=INT32_MIN;
    for(int start = 0;start<n;start++)
    {
        int currSum = 0;
        for(int end = start;end<n;end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout<<"Max Subarray Sum is: "<<maxSum;
}

int main() {
    int arr[6] = {2,-3,6,-5,4,2};
    int n = 6;

    max_sum2(arr,n);

    return 0;
}