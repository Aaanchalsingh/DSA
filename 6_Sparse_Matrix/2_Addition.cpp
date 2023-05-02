// ADDITION OF TWO SPARSE MATRIX
#include <bits/stdc++.h>
using namespace std;
class elements
{
public:
    int i;
    int j;
    int x;
} e;
class sparse
{

public:
    int m;
    int n;
    int num;
    elements *e;

    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new elements[num];
    }
    void creation()
    {
        e = new elements[num];
        cout << "ENTER ELEMENTS WITH THEIR INDICES : \n";
        for (int i = 0; i < num; i++)
        {
            cin >> e[i].i >> e[i].j >> e[i].x;
        }
        cout << "\n";
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((j == e[k].j) && (i == e[k].i))
                {
                    cout << e[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

sparse *Addition(sparse *a, sparse *b)
{
    int i, j, k;
    i = j = k = 0;
    sparse *sum = new sparse(4, 4, 8);
    sum->e = new elements[8];
    while ((i < a->num) && (j < b->num))
    {
        if (a->e[i].i < b->e[j].i)
        {
            sum->e[k++] = a->e[i++];
        }
        else if (a->e[i].i > b->e[j].i)
        {
            sum->e[k++] = b->e[j++];
        }
        else
        {
            if (a->e[i].j < b->e[j].j)
            {
                sum->e[k++] = a->e[i++];
            }
            else if (a->e[i].j > b->e[j].j)
            {
                sum->e[k++] = b->e[j++];
            }
            else
            {
                sum->e[k] = a->e[i];
                sum->e[k++].x = (a->e[i++].x) + (b->e[j++].x);
            }
        }
    }
    for (; i < a->num; i++)
    {
        sum->e[k++] = a->e[i];
    }
    for (; j < b->num; j++)
    {
        sum->e[k++] = b->e[j];
    }
    sum->num = k;
    return sum;
}
int main()
{
    sparse a(4, 4, 4), b(4, 4, 4), *c;
    a.creation();
    b.creation();
    c = Addition(&a, &b);
    a.display();
    b.display();
    c->display();
    return 0;
}