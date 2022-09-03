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

        void makeParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent)
        {
            queue<TreeNode*> q;
            q.push(root);
            parent[root] = NULL;

            while(q.size()) {
                TreeNode *top = q.front();
                q.pop();

                if(top->left) {
                    parent[top->left] = top;
                    q.push(top->left);
                }
                if(top->right) {
                    parent[top->right] = top;
                    q.push(top->right);
                }
            }
        }

        int minTime(TreeNode *root, TreeNode *target)
        {
            unordered_map<TreeNode*, TreeNode*> parent;
            makeParents(root, parent);

            unordered_map<TreeNode*, bool> visited;

            queue<TreeNode*> q;
            q.push(target);
            visited[target] = 1;
            int d = 0;
            while(q.size()) {
                int sz = q.size();
                ++d;
                for(int i = 0; i < sz; i++) {
                    TreeNode *top = q.front();
                    q.pop();

                    if(top->left && visited[top->left] == 0) {
                        q.push(top->left);
                        visited[top->left] = 1;
                    }
                    if(top->right && visited[top->right] == 0) {
                        q.push(top->right);
                        visited[top->right] = 1;
                    }
                    if(parent[top] && visited[parent[top]] == 0) {
                        q.push(parent[top]);
                        visited[parent[top]] = 1;
                    }
                }
            }
            return d - 1;

        }

        void preorder(TreeNode *root)
        {
            if(root == NULL) return ;

            cout << root->val <<" ";

            preorder(root->left);
            preorder(root->right);
        }
};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(1);


    TreeNode *target = new TreeNode(2);
    bt.root->left = target;

//    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);

    bt.root->left->left = new TreeNode(4);
    bt.root->left->right = new TreeNode(5);

    bt.root->left->left->left = new TreeNode(7);


    cout << bt.minTime(bt.root, target);


    return 0;
}
