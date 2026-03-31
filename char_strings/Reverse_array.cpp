#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char arr[] = "ApPle";
    int n = strlen(arr);

    int st = 0;
    int end = n-1;

    while(st<end)
    {
        swap(arr[st],arr[end]);
        st++; 
        end--;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
