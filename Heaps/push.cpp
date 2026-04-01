#include<bits/stdc++.h>
using namespace std;

class heap{
    vector<int> v;
    public:
    void push(int val)
    {
        v.push_back(val);

        int x = v.size() - 1;
        int par = (x-1)/2;
        while(v[par]<v[x])
        {
            swap(v[par],v[x]);
            x = par;
            par = (x-1)/2;
        }
    }

    void pop()
    {

    }

    int top()
    {

    }

    void empty()
    {

    }
};

int main() {
    heap h1;
    h1.push(8);    
    h1.push(8);    
    h1.push(8);    
    h1.push(8);    
    h1.push(8);    
    return 0;
}