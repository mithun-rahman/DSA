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

        int widthOfBinaryTree(TreeNode* root) {
            if(root == NULL) return 0;
            queue<pair<TreeNode*, int>> q;

            q.push({root, 1});
            int mx = 0;
            while(q.size()) {
                int sz = q.size();
                int l, r;
                for(int i = 0; i < sz; i++) {
                    auto top = q.front();
                    q.pop();

                    if(i == 0) l = top.second;
                    if(i == sz-1) r = top.second;

                    mx = max(mx, r-l+1);

                    if(top.first->left) {
                        q.push({top.first->left, 2*top.second});
                    }
                    if(top.first->right) {
                        q.push({top.first->right, 2*top.second + 1});
                    }
                }
            }
            return mx;
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

    bt.root->right->right = new TreeNode(7);

    cout <<bt.widthOfBinaryTree(bt.root) << endl;
    return 0;
}
