#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    for(int i=1;i<=5;i++)
    {
        q.push(i);
    }
    int k=3;

    stack<int> s;
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }

    int remaining = q.size();
    for(int i=0;i<k;i++)
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<remaining;i++)
    {
        q.push(q.front());
        q.pop();
    }

    for(int i=0;i<5;i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}