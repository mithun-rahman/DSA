#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
    public:
        TreeNode *root = NULL;
        int diameter = 0;

};

int main()
{
//    BinaryTree bt;
//
//    bt.root = new TreeNode(1);
//    bt.root->left = new TreeNode(2);
//    bt.root->right = new TreeNode(3);
//    bt.root->left->left = new TreeNode(4);
//
//    bt.root->left->right = new TreeNode(5);
//    bt.root->right->left = new TreeNode(6);
//    bt.root->right->right = new TreeNode(7);

    int n;
    n = 4;

    cout << n << endl;

    return 0;
}
