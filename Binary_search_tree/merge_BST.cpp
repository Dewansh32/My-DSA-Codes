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

Node* insert(Node* root,int val)
{
    if(root == NULL) 
    {
        root = new Node(val);
        return root;
    }

    if(val>root->data)
    {
        root->right = insert(root->right,val);
       
    }
    else{
        root->left = insert(root->left,val);
    }

    return root;
}

void inorder(Node* root,vector<int> &arr)
{
    if(root == NULL) return;

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* buildBST(int arr[],int n)
{
    Node* root = NULL;
    for(int i=0;i<n;i++)
    {
        root = insert(root,arr[i]);
    }

    return root;
}

void Merge_array(vector<int> &arr1,vector<int> &arr2,vector<int> &ans)
{
    int sz1 = arr1.size();
    int sz2 = arr2.size();
    int i=0,j=0;

    while(i<sz1 && j<sz2)
    {
        if(arr1[i]<=arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
    }

    while(i<sz1)
    {
        ans.push_back(arr1[i++]);
    }
    while(j<sz2)
    {
        ans.push_back(arr2[j++]);
    }
    
}

void preorder(Node* root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* MergeBST(vector<int> ans,int st,int end)
{
    if(st>end) return NULL;
    int mid = (st + end)/2;
    
    Node* root = new Node(ans[mid]);

    root->left = MergeBST(ans,st,mid-1);
    root->right = MergeBST(ans,mid+1,end);

    return root;
}

int main()
{
    int arr1[3] = {2,1,4};
    int arr2[3] = {9,3,12};

    Node* root1 = buildBST(arr1,3);
    Node* root2 = buildBST(arr2,3);

    vector<int> sarr1;
    vector<int> sarr2;
    inorder(root1,sarr1);
    inorder(root2,sarr2);

    vector<int> ans;

    Merge_array(sarr1,sarr2,ans);

    Node* root = MergeBST(ans,0,(sarr1.size() + sarr2.size())-1);
    preorder(root);

    return 0;
}