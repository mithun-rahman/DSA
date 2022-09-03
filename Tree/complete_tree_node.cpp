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

        int leftHieght(TreeNode *root)
        {
            int cnt = 0;
            while(root) {
                root = root->left;
                cnt++;
            }
            return cnt;
        }

        int rightHeight(TreeNode *root)
        {
            int cnt = 0;
            while(root) {
                root = root->right;
                cnt++;
            }
            return cnt;
        }

        int countNodes(TreeNode* root) {
            if(root == NULL) return 0;

            int left = leftHieght(root);
            int right = rightHeight(root);

            if(left == right) return (1<<left) - 1;

            return 1 + countNodes(root->left) + countNodes(root->right);
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

 //   bt.root->left->left->left = new TreeNode(7);


    cout << bt.countNodes(bt.root) << endl;


    return 0;
}
