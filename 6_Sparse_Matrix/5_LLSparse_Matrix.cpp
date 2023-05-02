// CREATION OF SPARSE MATRIX USING LINKED LIST
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int col;
    int data;
    node *next;
    node **D;
    node()
    {
        D = new node *[5];
    }
    ~node() {}

} *head = NULL, o;
void create(node *a)
{
    for (int i = 0; i < 3; i++)
    {
        a->D[i] = new node;
        cin >> a->D[i]->col >> a->D[i]->data;
    }
}
void display(node *a)
{
    for (int i = 0; i < 3; i++)
    {
        head = a->D[i];
        for (int j = 0; j < 3; j++)
        {
            if (j == head->col)
            {
                cout << head->data << " ";
                head = head->next;
            }
            else
            {
                cout << "\0 ";
            }
        }
        cout << "\n";
    }
}
int main()
{
    create(head);
    display(head);
    return 0;
}