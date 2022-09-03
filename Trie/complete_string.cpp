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
    private:
        node* root = new node();

    public:

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

        bool isComplete(string str)
        {
            node *temp = root;
            for(int i = 0; i < str.size(); i++) {
                int id = str[i]-'a';
                if(temp->next[id] == NULL) return 0;

                temp = temp->next[id];
                if(temp->endmark == 0) return 0;
            }
            return 1;
        }

        string Max(string x, string y)
        {
            if(x.size() > y.size()) return x;
            else if(x.size() < y.size()) return y;

            if(x > y) return y;
            return x;
        }

};

/*
A string is called complete if its all prefix is present in the string array.
*/

int main()
{
    Trie tr;

    tr.insert("n");
    tr.insert("ni");
    tr.insert("nin");
    tr.insert("ninj");
    tr.insert("ninja");
    tr.insert("ninga");

    cout << tr.Max("ab", "aa") << endl;

    cout <<tr.isComplete("ninja") <<endl;

    return 0;
}
