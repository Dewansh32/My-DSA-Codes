#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    
    stack<int> s;
    while(!Q.empty())
    {
        s.push(Q.front());
        Q.pop();
    }
    while(!s.empty())
    {
        Q.push(s.top());
        s.pop();
    }

    while(!Q.empty())
    {
        cout<<Q.front()<<" ";
        Q.pop();
    }
    return 0;
}