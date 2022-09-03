#include<bits/stdc++.h>

using namespace std;

struct node
{
    int cnt;
    bool endmark;
    node *next[27];

    node()
    {
        cnt = 0;
        endmark = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie
{
    public:
        node *root = new node();

        void insert(string str)
        {
            node *temp = root;
            for(int i = 0; i < str.size(); i++) {
                int id = str[i] - 'a';
                if(temp->next[id] == NULL) {
                    node *nptr = new node();
                    temp->next[id] = nptr;
                }
                temp = temp->next[id];
                temp->cnt++;
            }
            temp->endmark = 1;
        }

        bool search(string str)
        {
            node *temp = root;
            for(int i = 0; i < str.size(); i++) {
                int id = str[i] - 'a';
                if(temp->next[id] == NULL) {
                    return 0;
                }
                temp = temp->next[id];
            }
            return temp->endmark;
        }

        int Prefix(string str)
        {
            node *temp = root;
            for(int i = 0; i < str.size(); i++) {
                int id = str[i] - 'a';
                if(temp->next[id] == NULL) return 0;
                temp = temp->next[id];
            }
            return temp->cnt;
        }
};

int main()
{
    Trie tt;

    tt.insert("ac");
    tt.insert("aba");
    tt.insert("ab");

    cout << tt.Prefix("ac") << endl;
    return 0;
}
