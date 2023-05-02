// DELETING A BINARY SEARCH TREE
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

    int height(node *p)
    {
        int x, y;
        if (p)
        {
            x = height(p->left);
            y = height(p->right);
            if (x > y)
                return x + 1;
            else
                return y + 1;
        }
    }
    node *inorderpredecessor(node *p)
    {

        while (p && p->right)
        {
            p = p->right;
        }
        return p;
    }
    node *inorderSuceessor(node *p)
    {

        while (p && p->left)
        {
            p = p->left;
        }
        return p;
    }

    node *Delete(node *p, int key)
    {
        node *q;
        if (!p)
        {
            return NULL;
        }
        if (!p->left && !p->right)
        {
            if (p == root)
            {
                root = NULL;
            }
            delete[] p;
            return NULL;
        }
        if (key > p->data)
            p->right = Delete(p->right, key);
        else if (key < p->data)
            p->left = Delete(p->left, key);
        else
        {
            if (height(p->left) > height(p->right))
            {
                q = inorderpredecessor(p->left);
                p->data = q->data;
                p->left = Delete(p->left, q->data);
            }
            else
            {
                q = inorderSuceessor(p->right);
                p->data = q->data;
                p->right = Delete(p->right, q->data);
            }
        }
    }
} a;
int main()
{
    a.insert(20);
    a.insert(40);
    a.insert(10);
    a.insert(30);
    a.insert(25);
    a.inorder(a.root);
    cout << "\n";
    a.Delete(a.root, 20);
    a.inorder(a.root);

    return 0;
}
