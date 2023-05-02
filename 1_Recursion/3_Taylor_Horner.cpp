// TAYLOR SERIES
//  e^x = 1+x+x^2/2!+x^3/3!+x^4/4!--------
#include <bits/stdc++.h>
using namespace std;
double static u;
double taylor(int x, int n)
{
    if (n == 0)
    {
        return u;
    }
    else
    {
        u = (1 + x * u / n);
        return taylor(x, n - 1);
    }
}
int main()
{
    cout << taylor(2, 5);
    return 0;
}