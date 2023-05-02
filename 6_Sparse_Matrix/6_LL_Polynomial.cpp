// EVALUATION OF POLYNOMIAL
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int coeff;
    int exp;
    node *next;
} *head = NULL, *second = NULL;
void create(int size)
{
    cout << "ENTER THE COEFFICIENT AND EXPONENT FOR LIST 1 :\n";
    node *t, *last = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        t = new node;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (head == NULL)
        {
            head = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}
void createB(int size)
{
    cout << "\nENTER THE COEFFICIENT AND EXPONENT FOR LIST 2 :\n";
    node *t, *last = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        t = new node;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (second == NULL)
        {
            second = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}
void display(int x)
{
    int total = 0;
    node *p = head;
    while (p)
    {
        total += p->coeff * pow(x, p->exp);
        cout << p->coeff << "x^" << p->exp << " + ";
        p = p->next;
    }
    cout << "\nSUM = " << total;
}
void add()
{
    node *p = head;
    node *q = second;
    while (p && q)
    {
        if (p->exp == q->exp)
        {
            p->coeff += q->coeff;
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
            p = p->next;
        else
        {
            second = q->next;
            q->next = p;
            head = q;
            p = head;
            q = second;
            p = p->next;
        }
    }
}
int main()
{
    create(5);
    createB(3);
    add();
    display(1);

    return 0;
}