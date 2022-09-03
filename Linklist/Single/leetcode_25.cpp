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

        ListNode* reverse(ListNode *head)
        {
            ListNode *future, *rev;
            rev = NULL;

            while(head != NULL) {
                future = head->next;
                head->next = rev;
                rev = head;
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

        void reverseKGroup(ListNode* head, int k)
        {
            ListNode *temp, *tail, *prevTail,*revTail, *rev;

            rev = temp = NULL;
            int cnt = 0;
            while(head) {
                if(temp == NULL) {
                    revTail = temp = head;
                }
                else {
                    tail->next = head;
                }
                tail = head;
                head = head->next;
                cnt++;

                if(cnt == k) {
                    tail->next = NULL;
                    temp = reverse(temp);

                    if(rev == NULL) {
                        rev = temp;
                    }
                    else {
                        prevTail->next = temp;
                    }
                    cnt = 0;
                    temp = NULL;
                    prevTail = revTail;
                }
            }

            if(temp) {
                tail->next = NULL;
                prevTail->next = temp;

            }
            display(rev);
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
    xx.insertLast(6);
    xx.insertLast(7);
    xx.insertLast(8);

    xx.reverseKGroup(xx.head, 1);


    return 0;
}
