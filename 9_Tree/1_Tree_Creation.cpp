// CREATION OF BINARY TREE USING LINKED LIST
//#FOR CREATION OF BINARY TREE WE NEED TO UNDERSTAND THAT WE NEED TO TAKE Queue/Stack for Storing the address of head and child node
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
} a;
int main()
{
    a.creation();
    a.preorder(a.root);
    return 0;
}