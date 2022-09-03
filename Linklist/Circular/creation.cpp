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
    tail->next = head;
}

void deletion(int val)
{
    if(head -> val == val)
    {
        head = head->next;
        tail->next = head;
    }
    else {
        node *temp = head ;
        while(temp->next->val != val) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void display()
{
    node *temp = head;

    while(1) {
        cout << temp->val << " -> ";
        temp = temp->next;
        if(temp == head) break;
    }
    cout << temp->val << endl;
}

int main()
{
    add(8);
    add(9);
    add(5);
    add(2);
    display();
    deletion(2);
    display();
    return 0;
}
