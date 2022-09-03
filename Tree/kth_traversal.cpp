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

        int MorrisInorder(TreeNode *root, int k)
        {
            int cnt = 0;
            while(root) {
                if(root->left == NULL) {
                    cnt++;
                    if(cnt == k) break;
                    cout << root->val <<" ";
                    root = root->right;
                }
                else {
                    TreeNode *Left = root->left;
                    while(Left->right != NULL && Left->right != root) {
                        Left = Left->right;
                    }
                    if(Left->right == NULL) {
                        Left->right = root;
                        root = root->left;
                    }
                    else {
                        Left->right = NULL;
                        cnt++;
                        if(cnt == k) break;

                        cout << root->val << " ";
                        root = root->right;
                    }
                }
            }
            return root->val;
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

    cout << bt.MorrisInorder(bt.root, 3) << endl;

    return 0;
}
