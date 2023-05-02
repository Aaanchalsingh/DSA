// CREATION OF SPARSE MATRIX
#include <bits/stdc++.h>
using namespace std;
class elements
{
public:
    int i;
    int j;
    int x;
};
class sparse
{
    int m;
    int n;
    int num;
    elements *e;

public:
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
int main()
{
    sparse a(4, 4, 4);
    a.creation();
    a.display();
    return 0;
}