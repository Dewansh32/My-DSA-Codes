#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:

    void push(int val)
    {
        if(s1.empty())
        {
            s1.push(val);
            return;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop()
    {
        if(s1.empty())
        {
            cout<<"QUEUE EMPTY"<<endl;
            return;
        }
        cout<<"Value to pop: "<<s1.top()<<endl;
        s1.pop();
    }

    int front()
    {
        if(s1.empty())
        {
            cout<<"QUEUE EMPTY"<<endl;
            return -1;
        }
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main() {
    Queue q;

    cout << "---- Test 1: Pop on empty queue ----" << endl;
    q.pop();   // edge case

    cout << "\n---- Test 2: Front on empty queue ----" << endl;
    if(!q.empty())
        cout << q.front() << endl;
    else
        cout << "Queue is empty" << endl;

    cout << "\n---- Test 3: Push one element ----" << endl;
    q.push(10);
    cout << "Front element: " << q.front() << endl;

    cout << "\n---- Test 4: Pop single element ----" << endl;
    q.pop();

    cout << "\n---- Test 5: Queue empty after pop ----" << endl;
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl;

    cout << "\n---- Test 6: Push multiple elements ----" << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Front element should be 1: " << q.front() << endl;

    cout << "\n---- Test 7: Pop all elements (FIFO check) ----" << endl;
    while(!q.empty()) {
        q.pop();
    }

    cout << "\n---- Test 8: Pop again after clearing queue ----" << endl;
    q.pop();   // edge case again

    return 0;
}
