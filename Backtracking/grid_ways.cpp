#include<bits/stdc++.h>
using namespace std;

int grid_ways(int r,int c,int n,int m,string way)
{
    if (r >= n || c >= m) return 0; 
    if(r==n-1 && c==m-1)
    {
        cout<<way<<endl;
        return 1;
    }

    int v1 = grid_ways(r,c+1,n,m,way+'R');
    int v2 = grid_ways(r+1,c,n,m,way+'D');

    return v1 + v2;
}

int main() {
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;

    int m;
    cout<<"Enter number of columns: ";
    cin>>m;

    string way = "";

    cout<<grid_ways(0,0,n,m,way);

    return 0;
}