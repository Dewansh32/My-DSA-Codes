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

int sumofnodes(Node* root)
{
    int sum = 0;
    if(root == NULL)
    {
        return 0;
    }
    sum += root->data;
    sum += sumofnodes(root->left);
    sum += sumofnodes(root->right);

    return sum;
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    cout<<"sum of nodes: "<<sumofnodes(root)<<endl;

    return 0;
}