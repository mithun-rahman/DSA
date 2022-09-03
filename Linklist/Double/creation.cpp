#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *next, *prev;
    node()
    {
        next = prev = NULL;
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
        nptr->prev = tail;
    }
    tail = nptr;
}

void deletion(int val)
{
    if(val == head->val) {
        head = head->next;
        head->prev = NULL;
    }
    else if(val == tail->val) {
        tail = tail->prev;
        tail->next = NULL;
    }
    else {
        node *temp = head;
        while(temp->val != val) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}

void displayLR()
{
    node *temp = head;
    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayRL()
{
    node *temp = tail;
    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main()
{
    add(4);
    add(7);
    add(8);
    add(5);
    deletion(7);
    displayLR();
    displayRL();
    return 0;
}
