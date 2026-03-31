#include<bits/stdc++.h>
using namespace std;

class Node
{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }

};

static int idx = -1;

Node* buildTree(vector<int> nodes)
{
    idx++;
    if(nodes[idx] == -1)
    {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void kth(Node* root,int k,int l)
{
    if(root == NULL)
    {
        return;
    }

    if(l==k)
    {
        cout<<root->data<<" ";
        return;
    }

    if(l<k)
    {
        kth(root->left,k,l+1);
        kth(root->right,k,l+1);
    }
}

void kthLevel(Node* root,int k)
{
    int l = 1;
    kth(root,k,l);
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    int k=3;

    kthLevel(root,k);

    return 0;
}