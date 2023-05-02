// VARIOUS RECURSIVE TRAVERSAL TECHNIQUES
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
    }
    void inorder(node *p)
    {
        while (!s.isempty_Stack() || p != NULL)
        {
            if (p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.pop();
                cout << p->data << " ";
                p = p->right;
            }
        }
    }
    // void postorder(node *p)//#UNDER PROGRESS
    // {
    //     long int temp, n;
    //     while (!s.isempty_Stack() || p != NULL)
    //     {
    //         if (p != NULL)
    //         {
    //             s.push(p);
    //             p = p->left;
    //         }
    //         else
    //         {

    //             auto temp = s.pop();
    //             if (temp > 0)
    //             {
    //                 auto n = -1*temp;
    //                 s.push(n);
    //                 p = ((node *)temp)->right;
    //             }
    //             else
    //             {
    //                 cout << ((node *)temp)->data << " ";
    //                 p = NULL;
    //             }
    //         }
    //     }
    // }
    void levelorder(node *p)
    {
        cout << p->data << " ";
        r.ENqueue(p);
        while (!r.isempty())
        {
            p = r.Dequeue();
            if (p->left)
            {
                cout << p->left->data << " ";
                r.ENqueue(p->left);
            }
            if (p->right)
            {
                cout << p->right->data << " ";
                r.ENqueue(p->right);
            }
        }
    }
}

a;
int main()
{
    a.creation();
    cout << "\nPREORDER : ";
    a.preorder(a.root);
    cout << "\nINORDER : ";
    a.inorder(a.root);
    // cout << "\nPOSTORDER : ";//#UNDER PROGRESS
    // a.postorder(a.root);
    cout << "\nLEVELORDER : ";
    a.levelorder(a.root);
    return 0;
}