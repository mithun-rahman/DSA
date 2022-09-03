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

};

/*
A string is called complete if its all prefix is present in the string array.
*/

int main()
{
    Trie tr;

    string st;
    st = "sds";
    int cnt = 1;
    for(int i = 0; i < st.size(); i++) {
        string temp = "";
        for(int j = i; j < st.size(); j++) {
            temp += st[j];
            if(tr.search(temp) == 0) {
                cnt++;
                tr.insert(temp);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
