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

        ListNode* middle(ListNode *head)
        {
            ListNode *Hr, *Tr, *Prev;
            Hr = Tr = head;

            while(Hr  && Hr->next) {
                Hr = Hr->next->next;
                Prev = Tr;
                Tr = Tr->next;
            }
            Prev->next = NULL;

            return Tr;
        }
        ListNode* Merge(ListNode *L1, ListNode *L2)
        {
            ListNode *L3, *tail;
            L3 = NULL;
            while(L1 && L2) {
                if(L1->val < L2->val) {
                    if(L3 == NULL) {
                        L3 = L1;
                    }
                    else {
                        tail->next = L1;
                    }
                    tail = L1;
                    L1 = L1->next;
                }
                else {
                    if(L3 == NULL) {
                        L3 = L2;
                    }
                    else {
                        tail->next = L2;
                    }
                    tail = L2;
                    L2 = L2->next;
                }
            }
            while(L1) {
                tail->next = L1;
                tail = L1;
                L1 = L1->next;
            }
            while(L2) {
                tail->next = L2;
                tail = L2;
                L2 = L2->next;
            }
            tail->next = NULL;

            return L3;
        }

        ListNode* sortList(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }

            ListNode *mid = middle(head);

            ListNode *left = sortList(head);
            ListNode *right = sortList(mid);

            return Merge(left, right);
        }
};

int main()
{
    LL xx, yy ;

    xx.insertFirst(1);
    xx.insertLast(6);
    xx.insertLast(7);
    xx.insertLast(4);
    xx.insertLast(6);

    ListNode *ll = xx.sortList(xx.head);

    xx.display(ll);

    return 0;
}
