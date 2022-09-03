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

        void Reorder(ListNode* head)
        {
            int ln = Length(head);

            ListNode *mid = middle(head);
            mid = reverse(mid);

            display(head);
            display(mid);

            newhead = head;

            ListNode *f1, *f2;

            while(mid != NULL) {
                f1 = head->next;
                f2 = mid->next;

                head->next = mid;
                head = f1;

                mid->next = head;
                mid = f2;
            }
            if(head != NULL) head->next = NULL;
            display(newhead);
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

    xx.Reorder(xx.head);


    return 0;
}
