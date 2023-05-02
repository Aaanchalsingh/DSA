// INSERTING OR CREATING A BINARY SEARCH TREE
#include "Queue.h"
#include "Stack.h"
using namespace std;
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
            last = p;

            if (key == p->data)
            {

                return;
            }
            else if (key > p->data)
            {

                p = p->right;
            }
            else
            {

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
int main()
{
    // a.insert(20);
    // a.insert(40);
    // a.insert(10);
    // a.insert(30);
    // a.insert(25);
    root = rinsert(root, 20);
    rinsert(root, 40);
    rinsert(root, 10);
    rinsert(root, 30);
    rinsert(root, 25);
    inorder(root);
    cout << endl;
    preorder(root);
    return 0;
}
