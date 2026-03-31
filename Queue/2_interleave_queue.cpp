#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);
    Q.push(9);
    Q.push(10);


    queue<int> q1;
    queue<int> q2;
    int n = Q.size();

    for(int i=0;i<n/2;i++)
    {
        q1.push(Q.front());
        Q.pop();
    }
    for(int i=n/2;i<n;i++)
    {
        q2.push(Q.front());
        Q.pop();
    }

    int arr[n];
    int count=0;
    int size = q1.size();
    for(int i=0;i<size;i++)
    {
        arr[count]=q1.front();
        q1.pop();
        count++;
        arr[count]=q2.front();
        q2.pop();
        count++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}