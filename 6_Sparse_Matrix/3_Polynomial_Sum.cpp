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
        cout << total;
    }
};
int main()
{
    polynomial s(5);
    s.create();
    s.sum(1);

    return 0;
}