#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    node *next[27];

    node()
    {
        endmark = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie
{
    public:
        node* root = new node();

        void insert(string str)
        {
            node* temp = root;
            for(int i = 0; i < str.size(); i++) {
                int id = str[i] - 'a';

                if(temp->next[id] == NULL) {
                    node *nptr = new node();
                    temp->next[id] = nptr;
                }
                temp = temp->next[id];
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

        void remove(string str)
        {
            node *temp = root;
            for(int i = 0; i < str.size(); i++) {
                int id = str[i] - 'a';
                temp = temp->next[id];
            }
            temp->endmark = 0;
        }
};

int main()
{
    Trie tr;

    tr.insert("algo");
    tr.insert("algea");
    tr.insert("also");
    tr.insert("tom");
    tr.insert("to");

    tr.remove("also");

    cout <<tr.search("also") <<endl;
    return 0;
}
