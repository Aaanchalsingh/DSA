// CIRCULAR QUEUE
#include <bits/stdc++.h>
using namespace std;
class queue
{
public:
    int front;
    int rear;
    int size;
    int *Q;
    queue()
    {
        size = 5;
        front = 0;
        rear = -1;
        Q = new int[size];
    }
    void Enqueue(int x)
    {
        if (((rear + 1) % size) == (size - 1))//MODULUS TYPE 
        {
            cout << "QUEUE FULL" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }
    void DEqueue()
    {
        if (rear == front)
            cout << "QUEUE EMPTY" << endl;
        else
            front = (front + 1) % size;
    }
    void display()
    {
        int p = front;
        int q = rear;
        do
        {
            cout << Q[p];
            p++;
        } while (p != q);
        cout << Q[p];
    }
} p;
int main()
{
    p.Enqueue(1);
    p.Enqueue(2);
    p.Enqueue(3);
    p.Enqueue(4);
    p.Enqueue(5);
    p.Enqueue(6);
    p.DEqueue();
    p.display();
    return 0;
}