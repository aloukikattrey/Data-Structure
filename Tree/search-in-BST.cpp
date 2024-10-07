// it is a type of tree where elements lesser than root are on its left and greater are on its right
// and it is applicable to all nodes in the tree
// inorder of a BST is always in ascending order

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *InsertBST(node *root, int val)
{

    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = InsertBST(root->left, val);
    }
    else
    {
        // when val< root->val
        root->right = InsertBST(root->right, val);
    }
    return root;
}
node *searchInBST(node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }

    if (key < root->data)
    {
        return searchInBST(root->left, key);
    }

    return searchInBST(root->right, key);
}

int main()
{
    node *root = NULL;
    root = InsertBST(root, 5);
    InsertBST(root, 1);
    InsertBST(root, 3);
    InsertBST(root, 4);
    InsertBST(root, 2);
    InsertBST(root, 7);

    cout<<"enter key";
    int key;cin>>key;
    
    if(searchInBST(root,key)==NULL){
        cout<<"key do not exist";
    }else{
        cout<<"key exist";
    }
    return 0;
}