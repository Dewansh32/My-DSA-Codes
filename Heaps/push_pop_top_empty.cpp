#include<bits/stdc++.h>
using namespace std;

class heap {
    vector<int> v;

public:
    // Insert into heap
    void push(int val)
    {
        v.push_back(val);

        int x = v.size() - 1;
        int par = (x - 1) / 2;

        // Heapify up
        while (x > 0 && v[par] < v[x])
        {
            swap(v[par], v[x]);
            x = par;
            par = (x - 1) / 2;
        }
    }

    // Heapify down
    void heapify(int idx)
    {
        int c1 = 2 * idx + 1;
        int c2 = 2 * idx + 2;

        int maxidx = idx;

        if (c1 < v.size() && v[c1] > v[maxidx])
        {
            maxidx = c1;
        }

        if (c2 < v.size() && v[c2] > v[maxidx])
        {
            maxidx = c2;
        }

        if (idx != maxidx)
        {
            swap(v[idx], v[maxidx]);
            heapify(maxidx); // 🔥 important
        }
    }

    // Remove max element
    void pop()
    {
        if (v.empty()) return;

        swap(v[0], v[v.size() - 1]);
        v.pop_back();

        if (!v.empty())
            heapify(0);
    }

    // Get max element
    int top()
    {
        if (v.empty()) return -1; // safe check
        return v[0];
    }

    // Check if empty
    bool empty()
    {
        return v.empty();
    }
};

int main() {
    heap h1;

    h1.push(8);
    h1.push(4);
    h1.push(5);
    h1.push(1);
    h1.push(2);
    h1.push(9);

    cout << h1.top() << endl; // should print 9

    h1.pop();

    cout << h1.top() << endl; // should print 9

    return 0;
}