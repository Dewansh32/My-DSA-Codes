#include<bits/stdc++.h>
using namespace std;

class Queue{
    int* arr;
    int size;
    int currsize;

    int f,r;
    public:
    Queue(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        currsize = 0;

        f = r = -1;
    }

    void push(int val)
    {
        if(currsize == size) 
        {
            cout<<"Queue FULL"<<endl;
            return;
        }

        if(r == -1)
        {
            r = f = 0;
            arr[r] = val;
            currsize++;
            return;
        } 
        
        r = (r+1)%size;
        arr[r] = val;
        currsize++;
    }

    void pop()
    {
        if(currsize == 0)
        {
            cout<<"Queue empty"<<endl;
            return;
        }
        f = (f+1)%size;
        currsize--;
    }

    int front()
    {
        if(currsize == 0)
        {
            cout<<"Queue empty"<<endl;
            return -1;
        }

        return arr[f];
    }

    bool empty()
    {
        return currsize == 0;
    }

};

int main() {
    Queue q(5);

    cout << "---- Test 1: Pop on empty queue ----\n";
    q.pop();   // should say "Queue empty"

    cout << "\n---- Test 2: Front on empty queue ----\n";
    cout << q.front() << endl;  // should say "Queue empty"

    cout << "\n---- Test 3: Push elements ----\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "\n---- Test 4: Push on full queue ----\n";
    q.push(60);  // should say "Queue FULL"

    cout << "\n---- Test 5: Front element ----\n";
    cout << q.front() << endl;  // should print 10

    cout << "\n---- Test 6: Pop some elements ----\n";
    q.pop();  // removes 10
    q.pop();  // removes 20

    cout << "Front after pops: " << q.front() << endl; // should be 30

    cout << "\n---- Test 7: Circular queue behavior ----\n";
    q.push(60);
    q.push(70); // should wrap around

    cout << "Front now: " << q.front() << endl; // should still be 30

    cout << "\n---- Test 8: Empty the queue completely ----\n";
    while (!q.empty())
    {
        cout << "Front: " << q.front() << endl;
        q.pop();
    }

    cout << "\n---- Test 9: Final pop on empty queue ----\n";
    q.pop(); // should say "Queue empty"
    return 0;
}