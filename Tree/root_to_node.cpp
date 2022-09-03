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

struct Node
{
    int val, vert, level;

    Node(int val, int vert)
    {
        this->val = val;
        this->vert = vert;
    }
};

class BinaryTree
{
    public:
        TreeNode *root = NULL;

        bool getPath(TreeNode *root, int x, vector<int> &vt)
        {
            if(root == NULL) return 0;

            vt.push_back(root->val);

            if(root->val == x) {
                return 1;
            }

            if(getPath(root->left, x, vt) || getPath(root->right, x, vt)) return 1;

            vt.pop_back();

            return 0;
        }
};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(1);

    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);

    bt.root->left->left = new TreeNode(4);
    bt.root->left->right = new TreeNode(5);

    bt.root->right->left = new TreeNode(7);

    vector<int> vt;

    bt.getPath(bt.root, 7, vt);

    for(int i = 0; i < vt.size(); i++) {
        cout << vt[i] <<" ";
    }

    return 0;
}
