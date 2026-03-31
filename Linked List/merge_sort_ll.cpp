#include<bits/stdc++.h>
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
public:                // <-- made public so main() can access it exactly like in your original code
    Node* head;
    LList() {
        head = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {  // empty list
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {  // go to last node
            temp = temp->next;
        }
        temp->next = newNode;  // attach new node
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LList() {
        while (head != nullptr) {
            pop_front();
        }
    }
    int getSize(Node* head) {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) { // traverse until the end
            count++;
            temp = temp->next;
        }

        return count;
    }

    Node* merge(Node* head,Node* rightHead)
    {
        static LList ans;
        Node* i = head;
        Node* j = rightHead;

        while(i != NULL && j != NULL)
        {
            if(i->data <= j->data)
            {
                ans.push_back(i->data);
                i = i->next;
            }
            else{
                ans.push_back(j->data);
                j = j->next;
            }
        }

        while(i != NULL)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        while(j != NULL)
        {
            ans.push_back(j->data);
            j = j->next;
        }

        Node* result = ans.head; // take ownership of the built list
        ans.head = nullptr;      // detach so ans's destructor won't delete nodes
        return result;
    }

    Node* splitAtMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL)
        {
             prev->next = NULL;
        }

        return slow;
    }

    Node* mergeSort(Node* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        Node* rightHead = splitAtMid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        return merge(left,right);
    }
};

int main() {
    LList ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    ll.head = ll.mergeSort(ll.head); // <-- assign sorted head back to ll.head

    // optional: print to verify (kept minimal; you can remove if you don't want it)
    ll.print();

    return 0;
}
