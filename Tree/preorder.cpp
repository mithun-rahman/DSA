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

        void preorder(TreeNode *root)
        {
            if(root == NULL) {
                return ;
            }

            cout << root->val << " ";

            preorder(root->left);
            preorder(root->right);
        }

        void inorder(TreeNode *root)
        {
            if(root == NULL) {
                return ;
            }

            inorder(root->left);

            cout << root->val << " ";

            inorder(root->right);
        }

        void postorder(TreeNode *root)
        {
            if(root == NULL) {
                return ;
            }

            postorder(root->left);
            postorder(root->right);

            cout << root->val << " ";
        }

};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(1);
    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);
    bt.root->left->left = new TreeNode(4);
//    bt.root->left->left->left = new TreeNode(5);
    bt.root->left->right = new TreeNode(5);
//    bt.root->right->left = new TreeNode(6);
//    bt.root->right->right = new TreeNode(7);

    cout << "pre ";
    bt.preorder(bt.root);
    cout << endl;
    cout << "post ";
    bt.postorder(bt.root);
    cout << endl;
    cout << "in ";
    bt.inorder(bt.root);

    return 0;
}
