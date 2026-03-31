#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* append(Node* &tail, int value) {
    Node* n = new Node(value);
    if (tail) tail->next = n;
    tail = n;
    return n;
}

void printList(Node* head) {
    for (Node* p = head; p; p = p->next) {
        cout << p->val;
        if (p->next) cout << " -> ";
    }
    cout << endl;
}

Node* deleteNAfterM(Node* head, int M, int N) {
    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL)
    {
        for(int i=0;i<M && temp != NULL;i++)
        {
            prev = temp;
            temp = temp->next;
        }
        for(int i=0;i<N && temp != NULL;i++)
        {
            temp = temp->next;
        }
        prev->next = temp;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;
    append(tail, 2);
    append(tail, 3);
    append(tail, 4);
    append(tail, 5);
    append(tail, 6);
    append(tail, 7);
    append(tail, 8);

    cout << "Original: ";
    printList(head);

    int M = 2;
    int N = 2;

    head = deleteNAfterM(head, M, N);

    cout << "Result: ";
    printList(head);

    return 0;
}
