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
        int pos[2003];
        int off = 1000;

        TreeNode* constructTree(int inbeg, int inend, int prbeg, int prend,
            vector<int>& preorder, vector<int>& inorder)
        {
            if(inbeg > inend || prbeg > prend) {
                return NULL;
            }

            TreeNode *root = new TreeNode(preorder[prbeg]);

            int r = pos[preorder[prbeg]+off];
            int d = r - inbeg;

            root->left = constructTree(inbeg, r-1, prbeg+1, prbeg + d, preorder, inorder);
            root->right = constructTree(r+1, inend, prbeg+1+d, prend, preorder, inorder);

            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

            for(int i = 0; i < inorder.size(); i++) {
                pos[inorder[i]+off] = i;
            }

            int n = preorder.size()-1;
            TreeNode *root = constructTree(0, n, 0, n, preorder, inorder);

            return root;
        }

        void preorder(TreeNode *root)
        {
            if(root == NULL) return ;

            cout << root->val << endl;

            preorder(root->left);
            preorder(root->right);
        }

};

int main()
{
    BinaryTree bt;

    vector<int> pre, in;

    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(5);
    pre.push_back(3);


    in.push_back(4);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(3);


    TreeNode *root = bt.buildTree(pre, in);



    bt.preorder(root);


    return 0;
}
