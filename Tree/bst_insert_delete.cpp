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

        void insert(TreeNode *root, int key)
        {
            while(root) {
                int v = root->val;
                if(v > key) {
                    if(root->right == NULL) {
                        root->right = new TreeNode(key);
                        break;
                    }
                    root = root->left;
                }
                else {
                    if(root->left == NULL) {
                        root->left = new TreeNode(key);
                        break;
                    }
                    root = root->right;
                }
            }
        }

        TreeNode *RightMost(TreeNode *root)
        {
            TreeNode *prev = root;
            while(root) {
                prev = root;
                root = root->right;
            }
            return prev;
        }

        TreeNode *helper(TreeNode *root)
        {
            if(root->left == NULL) return root->right;
            if(root->right == NULL) return root->left;

            TreeNode *pp = RightMost(root->left);
            pp->right = root->right;

            return root->left;
        }

        TreeNode* deleteNode(TreeNode* root, int key) {
            TreeNode *temp, *prev, *left, *right;

            prev = NULL;
            temp = root;
            while(temp) {
                int v = temp->val;
                if(v == key) break;
                prev = temp;
                if(v > key) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            if(temp == NULL) return root;
            if(prev == NULL) {
                root = helper(temp);
            }
            else {
                if(prev->val > temp->val) {
                    prev->left = helper(temp);
                }
                else {
                    prev->right = helper(temp);
                }
            }
            return root;
        }

        void preorder(TreeNode *root)
        {
            if(root==NULL) return ;

            cout << root->val << " " ;
            preorder(root->left);
            preorder(root->right);
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

    TreeNode *xx = bt.deleteNode(bt.root, 4);
    bt.preorder(xx);

    return 0;
}
