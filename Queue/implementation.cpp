#include<bits/stdc++.h>

using namespace std;

class Queue {
public:
    int *arr;
    int size;
    int qfront;
    int rear;
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if(rear == size) {
            cout << "Queue is Full" << endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if(qfront == rear) {
                qfront = rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else {
            return arr[qfront];
        }
    }
};

int main()
{
    return 0;
}
