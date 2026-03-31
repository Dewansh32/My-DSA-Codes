#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LList {
public:
    Node* head;
    Node* tail;

    LList() : head(nullptr), tail(nullptr) {}

    void push_front(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head = n;
        }
    }

    void push_back(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }


    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    bool isCycle()
    {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
            {
                cout<<"CYCLE exists"<<endl;
                return true;
            }
        }
        cout<<"CYCLE don't exist"<<endl;
        return false;
    }

    void remove_cycle()
    {
        //detect cycle
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
            {
                isCycle = true;  
                break; 
            }
        }
        if(!isCycle)
        {
            cout<<"Cycle doesn't exist"<<endl;
            return;
        }

        slow = head;
        if(slow == fast)// special case: tail->next
        {
            while(fast->next != head)
            {
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }

        Node* prev = fast;
        while(slow == fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
        return;
    }
};

int main() {
    LList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.tail->next = list.head;

    list.remove_cycle();
    list.print();

    return 0;
}
