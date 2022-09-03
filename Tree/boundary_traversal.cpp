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

        void BoundaryOrder(TreeNode *root)
        {
            vector<int> left, right, leaf;
            queue<TreeNode*> q;
            q.push(root);

            while(q.size()) {
                int sz = q.size();
                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    if(top->left || top->right) {
                        if(i == 0) {
                            left.push_back(top->val);
                        }
                        else if(i == sz - 1) {
                            right.push_back(top->val);
                        }
                    }
                    else {
                        leaf.push_back(top->val);
                    }

                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
            }
            reverse(right.begin(), right.end());

            left.insert(left.end(), leaf.begin(), leaf.end());
            left.insert(left.end(), right.begin(), right.end());
            for(int i = 0; i < left.size(); i++) {
                cout << left[i] << " ";
            }
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

    bt.root->right->left = new TreeNode(6);
    bt.root->right->right = new TreeNode(7);

    bt.BoundaryOrder(bt.root);

    return 0;
}
