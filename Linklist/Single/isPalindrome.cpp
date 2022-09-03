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
        ListNode *head, *tail;
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

            while(temp != NULL) {
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

        bool isPalindrome(ListNode *head)
        {
            ListNode* mid = middle(head);

            mid = reverse(mid);

            while(mid != NULL) {
                if(mid->val != head->val) return 0;
                mid = mid->next;
                head = head->next;
            }

            return 1;
        }
};

int main()
{
    LL xx, yy ;

    xx.insertFirst(1);
    xx.insertLast(2);
    xx.insertLast(2);


    xx.display(xx.head);

    return 0;
}
