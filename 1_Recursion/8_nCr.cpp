// USING INDIRECT RECURSIVE APPROACH
#include <bits/stdc++.h>
using namespace std;
int fact(int a)
{
    if (a <= 1)
    {
        return 1;
    }
    else
    {
        return fact(a - 1) * a;
    }
}
int C(int n, int r)
{
    int a, b, c;
    a = fact(n);
    b = fact(r);
    c = fact(n - r);
    return a / (b * c);
}
int main()
{
    cout << C(4, 2);
    return 0;
}