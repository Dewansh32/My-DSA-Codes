#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
    // No destructor that deletes next — llist will manage node deletion.
};

class llist {
    Node* head;
    Node* tail;

public:
    llist() : head(nullptr), tail(nullptr) {}

    ~llist() {
        // Iteratively delete nodes to avoid recursion & double-deletes
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) // was empty before push
            tail = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else { // empty list
            head = tail = newNode;
        }
    }

    void insert(int val, int pos) {
        if (pos <= 1) { // insert at front
            push_front(val);
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (!temp) {
            cout << "Pos out of bounds\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    void pop_front() {
        if (!head) return; // empty
        Node* temp = head;
        if (head == tail) { // single node
            head = tail = nullptr;
            delete temp;
            return;
        }
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (!head) return; // empty
        if (head == tail) { // single node
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    int i_search(int val) {
        int idx = 1;
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // safer recursive search: returns 1-based index or -1
    int r_search_rec(Node* node, int key) {
        if (!node) return -1;          // not found
        if (node->data == key) return 1; // found at this node
        int res = r_search_rec(node->next, key);
        if (res == -1) return -1;
        return res + 1;
    }

    int r_search(int key) {
        return r_search_rec(head, key);
    }

    void reverse()
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* temp;
        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;  
        }
        head = prev;
    }

    void remove_nth_last(int n)
    {
        if (head == NULL) return;

        // Step 1: Count the nodes
        Node* temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        // Step 2: Validate n
        if (n <= 0 || n > size) return;

        // Step 3: If removing the head
        if (n == size)
        {
            Node* to_delete = head;
            head = head->next;
            delete to_delete;
            return;
        }

        // Step 4: Find the (size - n - 1)th node
        Node* prev = head;
        for (int i = 1; i < size - n; i++)
        {
            prev = prev->next;
        }

        // Step 5: Delete the nth node from end
        Node* to_delete = prev->next;
        prev->next = prev->next->next;
        delete to_delete;
    }


    void print_ll() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    llist ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);

    ll.print_ll(); // 1->2->3->4->5->NULL

    ll.pop_front();
    ll.print_ll(); // 2->3->4->5->NULL

    cout << ll.i_search(4) << endl; // 3 (1-based)
    cout << ll.r_search(4) << endl; // 3 (1-based)
    cout << ll.r_search(42) << endl; // -1

    ll.reverse();
    ll.print_ll();

    ll.remove_nth_last(2);
    ll.print_ll();
    return 0;
}
