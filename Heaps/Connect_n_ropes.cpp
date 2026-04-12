#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr  = {4,3,2,6};

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
    }

    int tcost=0;
    int cc=0;

    while(pq.size() > 1)   // ✅ FIXED
    {
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        cc = min1 + min2;
        pq.push(cc);

        tcost += cc;
    }

    cout<<"Final total cost of connection ropes is: "<<tcost<<endl;

    return 0;
}