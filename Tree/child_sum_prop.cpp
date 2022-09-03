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

        void childSum(TreeNode *root)
        {
            if(root->left==NULL && root->right == NULL) return ;

            if(root->left && root->right) {
                if(root->left->val + root->right->val < root->val) {
                    root->left->val = root->val;
                    root->right->val = root->val;
                }
                childSum(root->left);
                childSum(root->right);

                root->val = root->left->val + root->right->val;
            }
            else if(root->left) {
                if(root->left->val  < root->val) {
                    root->left->val = root->val;
                }
                childSum(root->left);

                root->val = root->left->val ;
            }
            else if(root->right) {
                if(root->right->val < root->val) {
                    root->right->val = root->val;
                }
                childSum(root->right);
                root->right->val;
            }
        }

        void preorder(TreeNode *root)
        {
            if(root == NULL) return ;

            cout << root->val <<" ";

            preorder(root->left);
            preorder(root->right);
        }
};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(40);

    bt.root->left = new TreeNode(10);
    bt.root->right = new TreeNode(20);

    bt.root->left->left = new TreeNode(30);
    bt.root->left->right = new TreeNode(5);

    bt.root->right->left = new TreeNode(30);
    bt.root->right->right = new TreeNode(40);

    bt.childSum(bt.root);
    bt.preorder(bt.root);

    return 0;
}
