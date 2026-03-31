#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    char C = 'A'-1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            C++;
            cout<<C<<" ";
        }
        cout<<endl;
    }
    return 0;
}