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
            vector<int>& postorder, vector<int>& inorder)
        {
       //     cout << inbeg <<" " << inend << " || " << prbeg << " " << prend<< endl;
            if(inbeg > inend || prbeg > prend) {
                return NULL;
            }

            TreeNode *root = new TreeNode(postorder[prend]);

            int r = pos[postorder[prend]+off];
            int d = r - inbeg;

            root->left = constructTree(inbeg, r-1,  prbeg , prbeg+d-1, postorder, inorder);
            root->right = constructTree(r+1, inend, prbeg+d, prend-1, postorder, inorder);

            return root;
        }

        TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {

            for(int i = 0; i < inorder.size(); i++) {
                pos[inorder[i]+off] = i;
            }

            int n = postorder.size()-1;
            TreeNode *root = constructTree(0, n, 0, n, postorder, inorder);

            return root;
        }

        void postorder(TreeNode *root)
        {
            if(root == NULL) return ;


            postorder(root->left);
            postorder(root->right);

            cout << root->val << endl;
        }

};

int main()
{
    BinaryTree bt;

    vector<int> pre, in;

    pre.push_back(4);
    pre.push_back(5);
    pre.push_back(2);
    pre.push_back(3);
    pre.push_back(1);


    in.push_back(4);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(3);


    TreeNode *root = bt.buildTree(pre, in);



    bt.postorder(root);


    return 0;
}
