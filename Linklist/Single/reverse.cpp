#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *next;
    node()
    {
        next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *Reverse(node *head)
{
    node *future, *nptr, *rev, *temp;
    temp = head;
    rev = future = NULL;
    while(temp != NULL) {
        future = temp->next;
        temp->next = rev;
        rev = temp;
        temp = future;
    }
    return rev;
}

int main()
{
    node *head, *tail;
    head = tail = NULL;


    for(int i = 1; i <= 5; i++) {
        node *nptr = new node();
        nptr->val = i;

        if(head == NULL) {
            head = nptr;
        }
        else {
            tail->next = nptr;
        }
        tail = nptr;
    }
    node *temp = head;

    display(Reverse(temp));

    display(head);
    return 0;
}
