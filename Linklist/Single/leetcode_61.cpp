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

        void Insert(ListNode *nptr)
        {
            nptr->next;
            if(newhead == NULL) {
                newhead = nptr;
            }
            else {
                tail->next = nptr;
            }
            tail = nptr;
        }



        ListNode* middle(ListNode *head)
        {
            ListNode *Hr, *Tr;
            Hr = Tr = head;
            while(Hr != NULL && Hr->next != NULL) {
                Hr = Hr->next->next;
                Tr = Tr->next;
            }
            return Tr;
        }

        int Length(ListNode* head)
        {
            int cnt = 0;
            ListNode *temp = head;
            while(temp != NULL) {
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }

        ListNode* rotateRight(ListNode* head, int k) {
            int ln = Length(head);
            k = k%ln;
            if(k == 0) return head;
            int d = ln - k;


            ListNode *First, *Second, *tail;

            First = Second = NULL;

            while(head) {
                if(First == NULL) {
                    First = head;
                }
                else {
                    tail->next = head;
                }
                tail = head;
                head = head->next;
                d--;
                if(d == 0) break;
            }
            tail->next = NULL;


            while(head) {
                if(Second == NULL) {
                    Second = head;
                }
                else {
                    tail->next = head;
                }
                tail = head;
                head = head->next;
            }


            tail->next = First;

            return Second;
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
