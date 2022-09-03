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
        int pathsum = -100000;

        int heightMax(TreeNode *root)
        {
            if(root == NULL) return 0;

            int left, right;
            left = heightMax(root->left);
            right = heightMax(root->right);

            return max(left, right) + 1;
        }

        int isBalance(TreeNode *root)
        {
            if(root == NULL) return 0;

            int left, right;
            left = 1 + isBalance(root->left);
            right = 1 + isBalance(root->right);

            if(left < 0 || right < 0) return -1;
            if(abs(left-right) > 1) return -1;

            return max(left, right);
        }

        int Diameter(TreeNode *root)
        {
            if(root == NULL) return 0;

            int left, right;
            left = Diameter(root->left);
            right = Diameter(root->right);

            diameter = max(diameter, left+right + 1);

            return max(left, right) + 1;
        }

        int Pathsum(TreeNode *root)
        {
            if(root == NULL) return 0;

            int left, right ;

            left =  max(0, Pathsum(root->left)) ;
            right = max(0, Pathsum(root->right));

            pathsum = max(pathsum, left+right+root->val) ;

            return max(left, right) + root->val;
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
  //  bt.root->left->right = new TreeNode(5);
  //  bt.root->right->left = new TreeNode(6);
 //   bt.root->right->right = new TreeNode(7);
//
//    cout <<bt.isBalance(bt.root) << endl;
//    cout << bt.heightMax(bt.root) << endl;

  //  bt.Pathsum(bt.root);

    bt.Diameter(bt.root);

    cout << bt.diameter << endl;

    return 0;
}
