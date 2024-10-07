// preorder- root->left->right
// inorder- left-> root-> ->right
// postorder- left-> right -> root

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

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    // node root(1);

    /*
              1
            /    \
           2      3
          / \     / \
      NULL  4    NULL NULL

    */

    cout << "preorder:";
    preOrder(root);
    cout << endl;
    cout << "inorder:";
    inOrder(root);
    cout << endl;
    cout << "potsorder:";
    postOrder(root);

    return 0;
}