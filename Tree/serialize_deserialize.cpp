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

        string serialize(TreeNode* root) {
            if(root == NULL) return "";

            queue<TreeNode*> q;
            q.push(root);
            string s;

            while(q.size()) {
                int sz = q.size();

                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    if(top == NULL) s.append("#,");
                    else {
                        s.append(to_string(top->val)+',');
                        q.push(top->left);
                        q.push(top->right);
                    }
                }
            }
            return s;
        }
        TreeNode* deserialize(string data) {
            if(data.size() == 0) return NULL;


            stringstream s(data);
            string str;

            getline(s, str, ',');

            TreeNode *root = new TreeNode(stoi(str));
            queue<TreeNode*> q;
            q.push(root);

            while(q.size()) {
                int sz = q.size();
                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    getline(s, str, ',');
                    if(str == "#") {
                        top->left = NULL;
                    }
                    else {
                        top->left = new TreeNode(stoi(str));
                        q.push(top->left);
                    }
                    getline(s, str, ',');
                    if(str == "#") {
                        top->right = NULL;
                    }
                    else {
                        top->right = new TreeNode(stoi(str));
                        q.push(top->right);
                    }
                }
            }
            return root;
        }

        void preorder(TreeNode *root)
        {
            if(root == NULL) return ;

            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }

};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(1);
    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);
    bt.root->right->left = new TreeNode(4);

    bt.root->right->right = new TreeNode(5);
//    bt.root->right->left = new TreeNode(6);
//    bt.root->right->right = new TreeNode(7);

    bt.preorder(bt.root);
    cout << endl;
    string st = bt.serialize(bt.root) ;
    cout << st << endl;
    TreeNode *root = bt.deserialize(st);
    cout << endl;

    bt.preorder(root);

    return 0;
}
