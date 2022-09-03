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

        int Ceil(TreeNode *root, int key)
        {
            int ceil = -1;
            while(root) {
                int v = root->val;
                if(v >= key) {
                    ceil = v;
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return ceil;
        }

        int Floor(TreeNode *root, int key)
        {
            int floor = -1;
            while(root) {
                int v = root->val;
                if(v <= key) {
                    floor = v;
                    root = root->right;
                }
                else {
                    root = root->left;
                }
            }
            return floor;
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

    bt.root->right->left = new TreeNode(5);

    cout << bt.Floor(bt.root, 6) << endl;

    return 0;
}
