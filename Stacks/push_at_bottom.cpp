#include<bits/stdc++.h>
using namespace std;

void pushAB(stack<int> &S,int val)
{
    if(S.empty())
    {
        S.push(val);
        return;
    }
    int temp = S.top();
    S.pop();
    pushAB(S,val);
    S.push(temp);
}

void printStack(stack<int> s) {  // pass by value to preserve original stack
    cout << "Stack (top → bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main() {
    stack<int> S;

    S.push(3);
    S.push(2);
    S.push(1);
    printStack(S);
    
    pushAB(S,4);
    printStack(S);
    return 0;
}