// WELCOME TO LINKED LIST REFRESHING START TO DSA
#include <bits/stdc++.h> //RATINGS -> 90%
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    node() {}
} *head = NULL;
void creation(int *A, int n) //#no need to understand this right now
{                            //#TIPS FROM FUTURE BELOW
    node *t, *last;
    head = new node(A[0]);
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node(A[i]);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(int n)
{
    node *ptr = new node;
    ptr = head;
    for (int i = 0; i < n; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout<<endl;
}
void insert(int data, int pos)
{
    node *t = new node(data);
    if (head == NULL)
    {
        head = t;
    }
    else if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        node *p = head;
        int i = 0;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        t->next = p->next;
        p->next = t;
    }
}
void deletion(int pos)
{
    if (head == NULL)
    {
        return;
    }
    else if (pos == 0)
    {
        head = head->next;
    }
    else
    {
        node *p = head;
        int i = 0;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        if (p)
            p->next = p->next->next;
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, 8);
    insert(10, 0);
    display(9);
    deletion(8);
    display(8);
    return 0;
}
// 1.ALWAYS INITIALISE AND ALLOCATE MEMORY IN HEAP FOR HEAD POINTER
// THE WORK OF THE CREATION FUNCTION IS TO SET EVERYTHING LIKE ITS STARTING FROM HEAD SO GIVE ALL THE REQUIRED THINGS BY THE NODE CLASS I MEAN DATA AND NEXT POINTER SAME GOES FOR OTHER ELEMENTS IN THE KINKED LIST
// MORE GUIDELINES WILL BE GIVEN AFTER ANOTHER INSPECTION IN FUTURE
//#INSTRUCTIONS COMING SOON.....
