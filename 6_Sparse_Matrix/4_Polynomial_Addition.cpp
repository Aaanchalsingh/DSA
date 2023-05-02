// POLYNOMIAL ADDITION
#include <bits/stdc++.h>
using namespace std;
class term
{
public:
    int coeff;
    int exp;
};
class polynomial
{
public:
    int n;
    term *t;
    polynomial(int n)
    {
        this->n = n;
        t = new term[n];
    }
    void create()
    {
        cout << "ENTER COEFFICIENTS WITH THEIR POWER : \n";
        for (int i = 0; i < n; i++)
        {
            cin >> t[i].coeff >> t[i].exp;
        }
        cout << "\n";
    }

    void sum(int x)
    {
        int total = 0, i;
        for (i = 0; i < n; i++)
        {
            total += (t[i].coeff) * pow(x, t[i].exp);
        }
        cout << "(For x = 1) SUM = " << total;
    }
    polynomial add(polynomial s, polynomial p)
    {
        polynomial r(8);
        int i, j, k;
        j = k = i = 0;
        while ((i < s.n) && (j < p.n))
        {
            if ((s.t[i].exp) == (p.t[j].exp))
            {
                r.t[k].exp = s.t[i].exp;
                r.t[k++].coeff = (s.t[i++].coeff) + (p.t[j++].coeff);
            }
            else if ((s.t[i].exp) < (p.t[j].exp))
            {
                r.t[k++] = p.t[j++];
            }
            else
            {
                r.t[k++] = s.t[i++];
            }
        }
        for (; i < s.n; i++)
            r.t[k++] = s.t[i];
        for (; j < p.n; j++)
            r.t[k++] = p.t[j];
        r.n = k;
        return r;
    }
    void display(polynomial a)
    {
        for (int i = 0; i < a.n; i++)
        {
            cout << a.t[i].coeff << "x^" << a.t[i].exp << " + ";
        }
        cout << "\n";
    }
};
int main()
{
    polynomial s(5);
    s.create();
    polynomial p(3);
    p.create();
    polynomial r(8);
    r = s.add(s, p);
    s.display(s);
    p.display(p);
    r.display(r);
    r.sum(1);

    return 0;
}