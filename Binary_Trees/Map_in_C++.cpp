#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int,string> m;

    m[101] = "Rahul";
    m[110] = "Neha";
    m[115] = "Eren";

    cout<<m[101]<<endl;
    m[101] = "Mikasa";
    cout<<m[101]<<endl;

    cout<<m.count(101)<<endl;
    cout<<m.count(120)<<endl;

    for(auto it:m)
    {
        cout<<"Key: "<<it.first<<" Value: "<<it.second<<endl;
    }
    return 0;
}