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

class BinaryTree {
public:
    TreeNode *root = NULL;

    struct Node
    {
        int val, vert, level;

        Node(int val, int vert)
        {
            this->val = val;
            this->vert = vert;
        }
    };

    vector<vector<int>> Vertical(TreeNode *root)
    {
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> nodes;

        while(q.size()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                auto top = q.front();
                q.pop();

                int x = top.second.first;
                int y = top.second.second;

                nodes[x][y].insert(top.first->val);

                if(top.first->left) {
                    q.push({top.first->left, {x-1, y+1}});
                }
                if(top.first->right) {
                     q.push({top.first->right, {x+1, y+1}});
                }
            }
        }

        vector<vector<int>> vt;
        for(auto p: nodes) {
            vector<int> col;
            for(auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            vt.push_back(col);
        }

        return vt;

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};

        return Vertical(root);
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


    bt.Vertical(bt.root);
    return 0;
}
