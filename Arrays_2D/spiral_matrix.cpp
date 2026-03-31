#include<iostream>
using namespace std;

void spiral_matrix(int arr[][4],int n,int m)
{
    int scol = 0,srow = 0;
    int ecol = m-1,erow = n-1;

    while(scol<=ecol && srow<=erow)
    {
        //top
        for(int j=srow,i=scol;i<=ecol;i++)
        {
            cout<<arr[srow][i]<<" ";
        }
        srow++;
        //right
        for(int j=ecol,i=srow;i<=erow;i++)
        {
            cout<<arr[i][j]<<" ";
        }
        ecol--;
        //bottom
        if(srow<=erow)
        {
            for(int j=erow,i=ecol;i>=scol;i--)
            {
                cout<<arr[j][i]<<" ";
            }
            erow--;
        }

        //left
        if(scol<=ecol)
        {
            for(int j=scol,i=erow;i>=srow;i--)
            {
                cout<<arr[i][j]<<" ";
            }
            scol++;
        }
    }
}

int main() {
    int n=4,m=4;
    int arr[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };

    spiral_matrix(arr,n,m);


    return 0;
}