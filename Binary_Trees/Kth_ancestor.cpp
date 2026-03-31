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

int kthAstr(Node* root,int node,int k)
{
    if(root == NULL) return -1;

    if(root->data == node)
    {
        return 0;
    }

    int lleft = kthAstr(root->left,node,k);
    int lright = kthAstr(root->right,node,k);

    if(lleft == -1 && lright == -1)
    {
        return -1;
    }

    int validval = lleft == -1? lright:lleft;

    if(validval+1 == k)
    {
        cout<<"Kth Ancestor is: "<<root->data<<endl;
    }

    return validval + 1;
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    kthAstr(root,5,2);

    return 0;
}