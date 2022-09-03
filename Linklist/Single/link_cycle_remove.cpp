#include<bits/stdc++.h>

using namespace std;


 struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class LL
{
    public:

        ListNode *head, *tail, *newhead;
        int sz ;

        LL()
        {
            head = tail = NULL;
            sz = 0;
        }

        void insertFirst(int val)
        {
            ListNode *nptr = new ListNode(val);
            nptr->next = head;
            head = nptr;
            if(tail == NULL) {
                tail = head;
            }
            sz++;
        }

        void insertLast(int val)
        {
            ListNode *nptr = new ListNode(val);
            if(tail == NULL) {
                insertFirst(val);
                return;
            }
            tail->next = nptr;
            tail = nptr;
            sz++;
        }


        void display(ListNode* H)
        {
            ListNode *temp = H;

            while(temp ) {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout << "null " << endl;
        }

        ListNode* reverse(ListNode* head)
        {
            ListNode *future, *rev, *nptr;
            rev = NULL;
            while(head) {
                future = head->next;
                nptr = head;
                nptr->next = rev;
                rev = nptr;
                head = future;
            }
            return rev;
        }


};

int main()
{
    LL xx, yy ;

    xx.insertFirst(1);
    xx.insertLast(2);
    xx.insertLast(3);
    xx.insertLast(4);
    xx.insertLast(5);
//    xx.insertLast(6);
//    xx.insertLast(7);
//    xx.insertLast(8);

    int k = 5;

    ListNode *tt = xx.rotateRight(xx.head, k);

    xx.display(tt);

    return 0;
}
