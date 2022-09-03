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

        void leftView(TreeNode *root)
        {
            vector<int> vt;
            queue<TreeNode*> q;
            q.push(root);

            while(q.size()) {
                int sz = q.size();

                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    if(i == 0) vt.push_back(top->val);

                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
            }

            for(int i = 0; i < vt.size(); i++) {
                cout << vt[i]<< " ";
            }
            cout << endl;

         }

        void rightView(TreeNode *root)
        {
            vector<int> vt;
            queue<TreeNode*> q;
            q.push(root);

            while(q.size()) {
                int sz = q.size();

                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    if(i == sz - 1) vt.push_back(top->val);

                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
            }

            for(int i = 0; i < vt.size(); i++) {
                cout << vt[i]<< " ";
            }
            cout << endl;

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

    bt.leftView(bt.root);
    bt.rightView(bt.root);

    return 0;
}
