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
    // COUNTING NODE METHOD 1
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
    // COUNTING NODE METHOD 2
    int count2(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            return count(p->left) + count(p->right) + 1;
        }
        return 0;
    }
    // COUNTING NODE METHOD 3
    int count3(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = count(p->left);
            y = count(p->right);
        }
        if (p->left && p->right)
        {
            return x + y + 1;
        }

        return 0;
    }

} a;
int main()
{
    a.creation();
    cout << "\nPREORDER : ";
    a.preorder(a.root);
    cout << "\nCOUNT : " << a.count3(a.root);

    return 0;
}
