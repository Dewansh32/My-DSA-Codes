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

bool findpath(Node* root,int n,vector<int> &path)
{
    if(root == NULL) return false;

    path.push_back(root->data);
    if(root->data == n)
    {
        return true;
    }

    bool fp1 = findpath(root->left,n,path);
    bool fp2 = findpath(root->right,n,path);

    if(fp1 || fp2)
    {
        return true;
    }

    path.pop_back();
    return false;

}

void findLCA(Node* root,int n1,int n2)
{
    vector<int> path1, path2;

    if(!findpath(root, n1, path1) || !findpath(root, n2, path2))
    {
        cout << "Solution not found";
        return;
    }

    int i = 0;
    int lca = -1;

    while(i < path1.size() && i < path2.size())
    {
        if(path1[i] == path2[i])
            lca = path1[i];
        else
            break;
        i++;
    }

    cout << "LCA is: " << lca;
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    int n1 = 4;
    int n2 = 5;
    findLCA(root,n1,n2);

    return 0;
}