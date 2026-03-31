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

void levelorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* currNode = q.front();
        q.pop();
        if(currNode != NULL)
        {
            cout<<currNode->data<<" ";
            if(currNode->left != NULL)
            {
                q.push(currNode->left);
            }
            if(currNode->right != NULL)
            {
                q.push(currNode->right);
            }
        }
        else
        {
            cout << endl;

            if(!q.empty())   // 🔑 THIS LINE SAVES YOUR PROGRAM
                q.push(NULL);
        }
    }
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    levelorder(root);

    return 0;
}