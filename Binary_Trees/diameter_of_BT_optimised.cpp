#include<bits/stdc++.h>
using namespace std;

class Node{
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

static int idx = - 1;

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

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int height = max(leftHt,rightHt) + 1;

    return height;
}

pair<int,int> diam2(Node* root)
{
    if(root == NULL)
    {
        return make_pair(0,0);
    }

    pair<int,int> leftinfo = diam2(root->left);
    pair<int,int> rightinfo = diam2(root->right);

    int currDia = leftinfo.second + rightinfo.second + 1;
    int finalDia = max(currDia,max(leftinfo.first,rightinfo.first));
    int finalHt = max(leftinfo.second,rightinfo.second) + 1;

    return make_pair(finalDia,finalHt);
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"root-> "<<root->data<<endl;

    cout<<"Height of binary tree is: "<<height(root)<<endl;
    cout<<"Diameter of binary tree is: "<<diam2(root).first<<endl;

    return 0;
}