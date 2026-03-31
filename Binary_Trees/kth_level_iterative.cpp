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

void kthLevel(Node* root, int k)
{
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level = 1;

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL)
        {
            level++;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            if(level == k)
                cout << curr->data << " ";

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }

        if(level > k)
            break;
    }

    if(level <= k)
        cout << "Kth Level doesn't exist";
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    int k=3;

    kthLevel(root,k);

    return 0;
}