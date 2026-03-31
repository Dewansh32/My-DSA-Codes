#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char arr[] = "ApPle";
    int n = strlen(arr);

    for(int i=0;i<n;i++)
    {
        if(arr[i]>='A' && arr[i]<='Z') continue;
        int pos = arr[i] - 'a';
        arr[i] = 'A' + pos;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}