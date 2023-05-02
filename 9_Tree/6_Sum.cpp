// FINDING HEIGHT OF NODE
#include "Queue.h"
#include "Stack.h"
using namespace std;
class tree
{
public:
    node *root;
    tree()
    {
        root = NULL;
    }
    void creation()
    {
        int x;
        root = new node(10);
        root->left = root->right = NULL;
        q.ENqueue(root);
        node *t, *p;
        while (!q.isempty())
        {
            p = q.Dequeue();
            cout << "ENTER THE LEFT CHILD OF " << p->data << " ";
            cin >> x;
            if (x != -1)
            {
                t = new node(x);
                t->left = t->right = NULL;
                p->left = t;
                q.ENqueue(t);
            }
            cout << "ENTER THE RIGHT CHILD OF " << p->data << " ";
            cin >> x;
            if (x != -1)
            {
                t = new node(x);
                t->left = t->right = NULL;
                p->right = t;
                q.ENqueue(t);
            }
        }
    }
    void preorder(node *p)
    {
        while (p != NULL || !s.isempty_Stack())
        {
            if (p != NULL)
            {
                cout << p->data << " ";
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.pop();
                p = p->right;
            }
        }
        cout << endl;
    }
    int count(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = count(p->left);
            y = count(p->right);
            return x + y + 1;
        }
        return 0;
    }
    int Height(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = Height(p->left);
            y = Height(p->right);
            if (x > y)
            {
                return x + 1;
            }
            else
            {
                return y + 1;
            }
        }
        return 0;
    }
    int sum(node *p)
    {
        if (p != NULL)
            return sum(p->left) + sum(p->right) + p->data;
        return 0;
    }
} a;
int main()
{
    a.creation();
    cout << "\nPREORDER : ";
    a.preorder(a.root);
    cout << "\nCOUNT : " << a.count(a.root);
    cout << "\nHEIGHT : " << a.Height(a.root);
    cout << "\nSUM : " << a.sum(a.root);

    return 0;
}
