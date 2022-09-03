#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node* next;
    node()
    {
        next = NULL;
    }
};

node *head = NULL;
node *tail;

void add(int val)
{
    node *nptr = new node();
    nptr->val = val;

    if(head == NULL) {
        head = nptr;
    }
    else {
        tail->next = nptr;
    }
    tail = nptr;
}

void deletion(int val)
{
    node *temp = head;
    if(head -> val == val) head = head->next;

    while(temp->next->val != val) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void insert_rec(int v, int pos, node *temp)
{
    if(pos == 1) {
        node *nptr = new node();
        nptr->val = v;

        nptr->next = temp->next;
        temp->next = nptr;
        return;
    }

    insert_rec(v, pos-1, temp->next);
}

void display()
{
    node *temp = head;

    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    add(4);
    add(2);
    add(3);
    add(8);
    display();

    insert_rec(7, 4, head);
    display();
    return 0;
}
