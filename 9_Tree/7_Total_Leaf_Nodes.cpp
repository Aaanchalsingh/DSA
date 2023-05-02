// FINDING TOTAL NUMBER OF DIFFERENT TYPES OF NODES
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
    int Degree_ZERO(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = Degree_ZERO(p->left);
            y = Degree_ZERO(p->right);
            if ((p->left == NULL) && (p->right == NULL))
            {
                return x + y + 1;
            }
            else
            {
                return x + y;
            }
        }
        return 0;
    }
    int Degree_TWO(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = Degree_TWO(p->left);
            y = Degree_TWO(p->right);
            if ((p->left) && (p->right))
            {
                return x + y + 1;
            }
            else
            {
                return x + y;
            }
        }
        return 0;
    }
    int Degree_ONEorTWO(node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = Degree_ONEorTWO(p->left);
            y = Degree_ONEorTWO(p->right);
            if ((p->left) || (p->right))
            {
                return x + y + 1;
            }
            else
            {
                return x + y;
            }
        }
        return 0;
    }
    int Degree_ONE(node *p)
    {
        int x, y;
        if (p != nullptr)
        {
            x = Degree_ONE(p->left);
            y = Degree_ONE(p->right);
            if ((p->left != nullptr) ^ (p->right != nullptr))
            {
                return x + y + 1;
            }
            else
            {
                return x + y;
            }
        }
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
    cout << "\nLEAF NODE COUNT  : " << a.Degree_ZERO(a.root);
    cout << "\nDEGREE 2 NODE COUNT  : " << a.Degree_TWO(a.root);
    cout << "\nDEGREE 1 OR 2 NODE COUNT  : " << a.Degree_ONEorTWO(a.root);
    cout << "\nDEGREE 1 NODE COUNT  : " << a.Degree_ONE(a.root);

    return 0;
}
