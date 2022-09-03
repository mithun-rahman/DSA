#include<bits/stdc++.h>

using namespace std;

struct node
{
    node *next[3];
    node()
    {
        next[0] = next[1] = NULL;
    }
};

class Trie
{
    private:
        node *root = new node();

    public:
        void insert(int n)
        {
            node *temp = root;
            for(int i = 30; i >= 0; i--) {
                int id = 0;
                if((n >> i) & 1) {
                    id = 1;
                }
                if(temp->next[id] == NULL) {
                    node *nptr = new node();
                    temp->next[id] = nptr;
                }
                temp = temp->next[id];
            }
        }
        int Maxor(int n)
        {
            int res = 0;

            node *temp = root;

            for(int i = 30; i >= 0; i--) {
                int id = 0;
                if((n >> i) & 1) {
                    id = 1;
                }
                if(temp->next[id^1]) {
                    res += (1<<i);
                    temp = temp->next[id^1];
                }
                else {
                    temp = temp->next[id];
                }
            }

            return res;
        }
};
/*
6
3 10 5 25 2 8
*/

int main()
{
    Trie tr, trr;


    int arr[102], brr[102];

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= m; i++) cin >> brr[i];

    sort(arr+1, arr+n+1);

    int j = 1;
    for(int i = 1; i <= n; i++) {
        if(arr[i] <= brr[j]) {
            tr.insert(arr[i]);
        }
        else {
            ///cout <<arr[i]<<" U " <<" " <<brr[j] <<endl;
            cout << tr.Maxor(1) << endl;
            tr.insert(arr[i]);
            j++;
        }
    }

   // cout << j << endl;
    cout << tr.Maxor(1) << endl;

    return 0;
}
