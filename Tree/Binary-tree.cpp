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
        // initialise every node with
        // left and right child as null
        left = NULL;
        right = NULL;
    }
};

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);

    /*
              1
            /    \
           2      3
          / \     / \
      NULL  4    NULL NULL

    */

    return 0;
}