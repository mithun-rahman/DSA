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

        TreeNode* searchBST(TreeNode* root, int val) {

            while(root) {
                int v = root->val;
                if(v == val) {
                    break;
                }
                else if(val < v) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            return root;
        }

        void levelOrder(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);

            while(q.size()) {
                int sz = q.size();
                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    cout << top->val << " ";
                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
                cout << endl;
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

     bt.searchBST(bt.root, 2);
    bt.levelOrder(bt.searchBST(bt.root, 2));
    return 0;
}
