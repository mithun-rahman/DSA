#include<bits/stdc++.h>

using namespace std;

class Solution
{
    private:
        int r, c;
        vector<string> res;
        bool visit[15][15];

        struct node
        {
            node *next[27];
            bool isFinish;
            node()
            {
                for(int i = 0; i < 26; i++) {
                    next[i] = NULL;
                }
                isFinish = 0;
            }
        };


        void insert(node* root, string s)
        {
            for(int i = 0; i < s.size(); i++) {
                if(root->next[s[i]-'a'] == NULL) {
                    node *nptr = new node();
                    root->next[s[i]-'a'] = nptr;
                    root = nptr;
                }
                else {
                    root = root->next[s[i]-'a'];
                }
            }
            root->isFinish = 1;
        }

        void DFS(node* root, int x, int y, vector<vector<char>>& board, string word)
        {

            if(root->isFinish == 1) {
                res.push_back(word);
                root->isFinish = 0;
            }
            visit[x][y] = 1;
            if(x > 0 && root->next[board[x-1][y]-97] && !visit[x-1][y]) {

                DFS(root->next[board[x-1][y]-97], x-1, y, board, word+board[x-1][y]);
            }
            if(y > 0 && root->next[board[x][y-1]-97]&& !visit[x][y-1]) {

                DFS(root->next[board[x][y-1]-97], x, y-1, board, word+board[x][y-1]);
            }

            if(x < r && root->next[board[x+1][y]-97] && !visit[x+1][y]) {

                DFS(root->next[board[x+1][y]-97], x+1, y, board, word+board[x+1][y]);
            }
            if(y < c && root->next[board[x][y+1]-97] && !visit[x][y+1]) {

                DFS(root->next[board[x][y+1]-97], x, y+1, board, word+board[x][y+1]);
            }
            visit[x][y] = 0;
        }



    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            r = board.size()-1;
            c = board[0].size()-1;

            node *root = new node();

            for(int i = 0; i < words.size(); i++) {
                insert(root, words[i]);
            }



            string temp;
            memset(visit, 0,sizeof visit);
            for(int i = 0; i <= r; i++) {
                for(int j = 0;j <= c; j++) {
                    if(root->next[board[i][j]-97]) {
                        temp = "";
                        temp += board[i][j];
                        DFS(root->next[board[i][j]-97], i, j, board, temp);
                    }
                }
            }
            return res;
        }

};

int main()
{
    Solution ss;

    return 0;
}
