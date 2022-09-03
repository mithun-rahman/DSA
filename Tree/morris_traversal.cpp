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

        void morrisInorder(TreeNode *root)
        {
            while(root != NULL) {
                if(root->left) {
                    TreeNode *prev = root->left;

                    while(prev->right && prev->right != root) {
                        prev = prev->right;
                    }
                    if(prev->right == NULL) {
                        prev->right = root;
                        root = root->left;
                    }
                    else {
                        prev->right = NULL;
                        cout << root->val << " ";
                        root = root->right;
                    }
                }
                else {
                    cout << root->val << " ";
                    root = root->right;
                }
            }
        }
        void morrisPreorder(TreeNode *root)
        {
            while(root != NULL) {
                if(root->left) {
                    TreeNode *prev = root->left;

                    while(prev->right && prev->right != root) {
                        prev = prev->right;
                    }

                    if(prev->right == NULL) {
                        prev->right = root;
                        cout << root->val << " ";
                        root = root->left;
                    }
                    else {
                        prev->right = NULL;
                        root = root->right;
                    }
                }
                else {
                    cout << root->val << " ";
                    root = root->right;
                }
            }
        }

};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(4);

    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(7);

    bt.root->left->left = new TreeNode(1);

    bt.root->left->right = new TreeNode(3);
//    bt.root->right->left = new TreeNode(6);
//    bt.root->right->right = new TreeNode(7);

    bt.morrisInorder(bt.root);
    cout << endl;
    bt.morrisPreorder(bt.root);

    return 0;
}
