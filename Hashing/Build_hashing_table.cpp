#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key,int val)
    {
        this->key = key;
        this->val = val;
    }

    ~Node()
    {
        if(next != NULL)
        {
            delete next;
        }
    }
};

class Hashtable{
    int totSize;
    int currSize;
    Node* *table;

    int hashFunction(string key)
    {
        int idx=0;

        for(int i=0;i<key.size();i++)
        {
            idx = (idx + (key[i] * key[i]))%totSize;
        }

        return idx;
    }

    void rehash()
    {
        Node **oldtable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        table = new Node*[totSize];

        for(int i=0;i<totSize;i++)
        {
            table[i] = NULL;
        }

        currSize = 0;

        for(int i=0;i<oldSize;i++)
        {
            Node* temp = oldtable[i];
            while(temp != NULL)
            {
                insert(temp->key,temp->val);
                temp = temp->next;
            }

            if(oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }

        delete[] oldtable;

    }

public:
    Hashtable(int size=5)
    {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for(int i=0;i<totSize;i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key,int val)
    {
        int idx = hashFunction(key);

        Node* newNode = new Node(key,val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda > 1)
        {
            rehash();
        }
    }

    void remove(string key)
    {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while(temp != NULL)
        {

            if(temp->key == key)
            {
                if(temp == prev)
                {
                    table[idx] = temp->next;
                }
                prev->next = temp->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool exist(string key)
    {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp != NULL)
        {
            if(temp->key == key)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int search(string key)
    {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp != NULL)
        {
            if(temp->key == key)
            {
                return temp->val;
            }

            temp = temp->next;
        }

        return -1;
    }

    void print(){
        for(int i=0;i<totSize;i++)
        {
            cout<<"idx"<<i<<" -> ";
            Node* temp = table[i];
            while(temp != NULL)
            {
                cout<< "( "<<temp->key <<","<<temp->val<<" ) ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main() {

    Hashtable ht;

    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    ht.remove("US");
    ht.print();

    if(ht.exist("India"))
    {
        cout<<"india population: "<<ht.search("India") << endl;
    }
    
    return 0;
}