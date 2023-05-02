// GENERATING A BINARY SEARCH TREE FROM PREORDER
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
    void generatingBST(int pre[], int n)
    {
        int i = 0;
        root = new node(pre[i++]);
        root->left = root->right = NULL;
        node *p = root;

        while (i < n)
        {
            node *t = new node(pre[i++]);
            t->left = t->right = NULL;
            if (pre[i] < p->data)
            {
                s.push(p);
                p->left = t;
                p = t;
            }
            else if ((pre[i] > p->data) && (pre[i] < s.isempty_Stack() ? 32767 : s.stacktop()->data))
            {

                p->right = t;
                p = t;
            }
            else
            {
                p = s.pop();
            }
        }
    }
} a;
int main()
{
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    a.generatingBST(pre, sizeof(pre) / 4);
    a.preorder(a.root);

    return 0;
}
