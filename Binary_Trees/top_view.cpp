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

map<int,int> topview(Node* root)
{
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    map<int,int> m;
    while(!q.empty())
    {
        pair<Node*,int> currNode = q.front();
        q.pop();
        if(currNode.first != NULL)
        {
            if(!m.count(currNode.second))
            {
                m[currNode.second] = currNode.first->data;
            }
            if(currNode.first->left != NULL)
            {
                q.push({currNode.first->left,currNode.second - 1});
            }
            if(currNode.first->right != NULL)
            {
                q.push({currNode.first->right,currNode.second + 1});
            }
        }
    }

    return m;
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    map<int,int> tv = topview(root);

    for(auto it:tv)
    {
        cout<<"Key: "<<it.first<<" value: "<<it.second<<endl;
    }

    return 0;
}