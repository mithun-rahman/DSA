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

        void levelorder1(TreeNode *root)
        {
            queue<TreeNode*> q[3];
            int x = 0;
            q[x].push(root);
            vector<int> vt;
            while(q[x].size() != 0) {
                TreeNode *top = q[x].front();

                vt.push_back(top->val);
                q[x].pop();

                if(top->left) q[x^1].push(top->left);
                if(top->right) q[x^1].push(top->right);

                if(q[x].size() == 0) {
                    for(int i = 0; i < vt.size(); i++) {
                        cout << vt[i] << " ";
                    }
                    cout << endl;
                    vt.clear();
                    x = x ^ 1;
                }
            }
        }
        void levelorder2(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);

            vector<int> vt;

            while(q.size()) {

                int sz = q.size();

                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    vt.push_back(top->val);

                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }

                for(int i = 0;i < vt.size(); i++) {
                    cout << vt[i] << " ";
                }
                cout << endl;
                vt.clear();
            }
        }

        void zizagOrder(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            bool flag = 1;
            int pos ;

            while(q.size()) {
                int sz = q.size();
                vector<int> vt(sz);
                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    pos = i;
                    if(flag == 0) pos = sz - i - 1;
                    vt[pos] = top->val;

                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }
                flag = flag ^ 1;
                for(int i = 0; i < vt.size(); i++) {
                    cout << vt[i] << " " ;
                }
                cout <<endl;
            }
        }

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

//
//    cout <<bt.isBalance(bt.root) << endl;
//    cout << bt.heightMax(bt.root) << endl;
//
//    bt.levelorder1(bt.root);
//
//    cout << endl;
//    bt.zizagOrder(bt.root);

    bt.BoundaryOrder(bt.root);

    return 0;
}
