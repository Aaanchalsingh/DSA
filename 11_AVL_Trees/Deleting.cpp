// DELETING A BINARY SEARCH TREE
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    int height;
    node *right;
    node(int data)
    {
        this->data = data;
    }
    node() {}
} *root = NULL;
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
int Nodeheight(node *p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}
int balancefactor(node *p)
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl - hr;
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
node *LLrotation(node *p)
{
    node *pl = p->left;
    node *plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);
    if (root == p)
        root = pl;
    return pl;
}
node *RRrotation(node *p)
{
    node *pr = p->right;
    node *prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);
    if (root == p)
        root = pr;
    return pr;
}
node *RLrotation(node *p)
{
    node *pr = p->right;
    node *prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;

    prl->left = p;
    prl->right = pr;

    p->height = Nodeheight(p);
    prl->height = Nodeheight(prl);
    pr->height = Nodeheight(pr);
    if (root == p)
        root = prl;
    return prl;
}
node *LRrotation(node *p)
{
    node *pl = p->left;
    node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->right = p;
    plr->left = pl;

    p->height = Nodeheight(p);
    plr->height = Nodeheight(plr);
    pl->height = Nodeheight(pl);
    if (root == p)
        root = plr;
    return plr;
}

node *rinsert(node *p, int key)
{
    if (p == NULL)
    {
        node *t = new node(key);
        t->left = t->right = NULL;
        t->height = 1;
        return t;
    }
    if (key > p->data)
        p->right = rinsert(p->right, key);
    else if (key < p->data)
        p->left = rinsert(p->left, key);
    p->height = Nodeheight(p);
    if (balancefactor(p) == 2 && balancefactor(p->left) == 1)
    {
        return LLrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->right) == -1)
    {
        return RRrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->right) == 1)
    {
        return RLrotation(p);
    }
    else if (balancefactor(p) == 2 && balancefactor(p->left) == -1)
    {
        return LRrotation(p);
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
    {

        p->right = Delete(p->right, key);
    }
    else if (key < p->data)
    {
        p->left = Delete(p->left, key);
    }
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

    p->height = Nodeheight(p);
    if (balancefactor(p) == 2 && balancefactor(p->left) == 1)
    {
        return LLrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->right) == -1)
    {
        return RRrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->right) == 1)
    {
        return RLrotation(p);
    }
    else if (balancefactor(p) == 2 && balancefactor(p->left) == -1)
    {
        return LRrotation(p);
    }
    return p;
}

int main()
{

    int key[] = {10, 20, 30, 25, 28, 27, 5};
    root = rinsert(root, key[0]);
    for (int i = 1; i < sizeof(key) / 4; i++)
    {
        rinsert(root, key[i]);
    }
    preorder(root);
    cout << endl;
    Delete(root, 25);
    preorder(root);
    return 0;
}