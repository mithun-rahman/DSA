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

        void flatten(TreeNode *root)
        {
            TreeNode *head, *tail;
            head = NULL;
            while(root != NULL) {
                if(root->left) {
                    TreeNode *prev = root->left;

                    while(prev->right && prev->right != root) {
                        prev = prev->right;
                    }

                    if(prev->right == NULL) {
                        prev->right = root;

                        cout << root->val << " ";
                        TreeNode *temp = root;
                        root = root->left;

//                        temp->left = NULL;
//                        if(head == NULL) {
//                            head = temp;
//                        }
//                        else {
//                            tail->right = temp;
//                        }
//                        tail = temp;
                    }
                    else {
                        prev->right = NULL;
                        root = root->right;
                    }
                }
                else {
                    cout << root->val << " ";
                    TreeNode *temp = root;
                    root = root->right;
//
//                    if(head == NULL) {
//                        head = temp;
//                    }
//                    else {
//                        tail->right = temp;
//                    }
//                    tail = temp;
                }
            }
        }

};

int arr[103];
int dp[103][103];
vector<int> vt;

void way(int pos, int sum)
{
    if(sum == 0) {
        for(int i = 0; i < vt.size(); i++) {
            cout << vt[i]<< " ";
        }
        cout << endl;
        return ;
    }
    if(pos == 0) {
        return ;
    }
    if(dp[pos][sum]) {
        if(sum - arr[pos] >= 0) {
            vt.push_back(arr[pos]);
            way(pos-1, sum -arr[pos]);
            vt.pop_back();
        }
    }
    way(pos-1, sum);
}

int main()
{
    BinaryTree bt;
//
//    bt.root = new TreeNode(1);
//
//    bt.root->left = new TreeNode(2);
//    bt.root->right = new TreeNode(3);
//
//    bt.root->left->left = new TreeNode(4);
//
//    bt.root->left->right = new TreeNode(5);
////    bt.root->right->left = new TreeNode(6);
////    bt.root->right->right = new TreeNode(7);
//
//    TreeNode *prev = NULL;
//    bt.flatten(bt.root);

    arr[1] = 2; arr[2] = 3; arr[3] = 5;

    for(int i = 0; i  <= 4; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 5; j++) {
            int x1, x2 ;
            x1 = x2 = 0;
            if(j - arr[i] >= 0) x1 = dp[i-1][j - arr[i]];
            x2 = dp[i-1][j];
            dp[i][j] = x1|x2;
        }
    }
    cout << dp[3][5] << endl;
    way(3, 5);
    return 0;
}
