#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *left;
    node *middle;
    node *right;
    int ldata;
    int rdata;

    node()
    {
        left = right = middle = NULL;
    }
    node(int ldata, int rdata)
    {
        this->ldata = ldata;
        this->rdata = rdata;
        left = right = middle = NULL;
    }
} *root = NULL;
void preorder(node *p)
{
    if (p != NULL)
    {
        if (p->ldata != 0)
            cout << p->ldata << " ";
        if (p->rdata != 0)
            cout << p->rdata << " ";
        preorder(p->left);
        preorder(p->middle);
        preorder(p->right);
    }
}
node *creation(int key[], int n)
{
    int i = 0;
    root = new node(key[i++], key[i++]);
    node *p = root, *t, *q;
    while (i < n)
    {
        if (p == root || (p->ldata != 0 && p->rdata != 0))
        {
            t = new node(p->ldata, 0);
            p->ldata = p->rdata;
            p->rdata = 0;
            p->left = t;
            q = new node(key[i++], 0);
            p->middle = q;
        }
        node *t = new node(key[i], 0);
        if (key[i] > p->ldata)
        {
            p = p->right;
        }
        else if (key[i++] < p->ldata)
        {
            p = p->left;
        }
        else
        {
            p->rdata = t->rdata;
        }
    }

    return p;
}

int main()
{
    int key[] = {10, 20, 30, 40, 50};
    root = creation(key, 4);
    preorder(root);
    return 0;
}
