// INSERTING OR CREATING A BINARY SEARCH TREE
#include "Queue.h"
#include "Stack.h"
using namespace std;
class tree
{
public:
    node *root;
    tree() { root = NULL; }
    void inorder(node *p)
    {
        if (p != NULL)
        {
            inorder(p->left);
            cout << p->data << " ";
            inorder(p->right);
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
    void insert(int key)
    {
        node *p = root, *last = NULL;
        node *t = new node(key);
        t->left = t->right = NULL;
        if (root == NULL)
        {
            root = t;
            return;
        }
        else
        {
            while (p)
            {

                if (key == p->data)
                {
                    last = p;
                    return;
                }
                else if (key > p->data)
                {
                    last = p;
                    p = p->right;
                }
                else
                {
                    last = p;
                    p = p->left;
                }
            }
            if (last->data > key)
            {
                last->left = t;
            }
            else if (last->data < key)
            {
                last->right = t;
            }
        }
    }
    node *rinsert(node *p, int key)
    {
        node *t = new node(key);
        t->left = t->right = NULL;
        if (p == NULL)
        {
            p = t;
            return t;
        }
        else
        {
            if (key > p->data)
                p->right = rinsert(p->right, key);
            else if (key < p->data)
                p->left = rinsert(p->left, key);
            else
                return p;
        }
    }
    node *rsearch(node *p, int key)
    {
        if (p == NULL)
            return NULL;
        if (key == p->data)
            return p;
        else if (key > p->data)
            p->right = rsearch(p->right, key);
        else
            p->left = rsearch(p->left, key);
        return p;
    }
    node *isearch(int key)
    {
        node *p = root;
        while (p)
        {
            if (key == p->data)
                return p;
            else if (key > p->data)
                p = p->right;
            else
                p = p->left;
        }
        return NULL;
    }
} a;
int main()
{
    // a.insert(20);
    // a.insert(40);
    // a.insert(10);
    // a.insert(30);
    // a.insert(25);
    a.root = a.rinsert(a.root, 20);
    a.rinsert(a.root, 40);
    a.rinsert(a.root, 10);
    a.rinsert(a.root, 30);
    a.rinsert(a.root, 25);
    a.inorder(a.root);
    cout << endl;
    a.preorder(a.root);
    //node *t = a.isearch(20);
    // if (t)
    // {
    //     cout << "\nELEMENT FOUND : " << t->data;
    // }
    // else
    // {
    //     cout << "\nELEMENT NOT FOUND  ";
    // }
    node *n = a.rsearch(a.root, 21);
    if (n)
    {
        cout << "\nELEMENT FOUND : " << n->data;
    }
    else
    {
        cout << "\nELEMENT NOT FOUND  ";
    }

    return 0;
}
