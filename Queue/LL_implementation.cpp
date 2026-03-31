#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
    Node* head;
    Node* tail;

    public:

    Queue()
    {
        head = tail =NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL) head = tail = newNode;
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        Node* temp = head;
        if(head == NULL) cout<<"The queue is empty";
        cout<<"Value to pop is: "<<temp->data<<endl;
        head = head->next;
        delete temp;
    }

    int front()
    {
        if(head == NULL) cout<<"The queue is empty";
        return head->data;
    }

    bool empty()
    {
        return head==NULL;
    }

    void print_queue()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {

    Queue q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    q1.print_queue();
    
    q1.pop();
    
    q1.print_queue();
    
    return 0;
}