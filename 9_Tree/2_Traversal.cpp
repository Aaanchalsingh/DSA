// VARIOUS RECURSIVE TRAVERSAL TECHNIQUES
#include <bits/stdc++.h>
#include "Queue.h"
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
        if (p != NULL)
        {
            cout << p->data << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }
    void inorder(node *r)
    {
      if (r)
    {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    }
    void postorder(node *p)
    {
        if (p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout << p->data << " ";
        }
    }
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
            if (p->left)
            {
                cout << p->right->data << " ";
                r.ENqueue(p->right);
            }
        }
    }
} a;
int main()
{
    a.creation();
    // cout << "\nPREORDER : ";
    // a.preorder(a.root);
    cout << "\nINORDER : ";
    a.inorder(a.root);
    // cout << "\nPOSTORDER : ";
    // a.postorder(a.root);
    // cout << "\nLEVELORDER : ";
    // a.levelorder(a.root);
    return 0;
}