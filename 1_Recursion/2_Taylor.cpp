// TAYLOR SERIES
//  e^x = 1+x+x^2/2!+x^3/3!+x^4/4!--------
#include <bits/stdc++.h>
using namespace std;
double static p = 1, q = 1;
double r = 0;
double taylor(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        r = taylor(x, y - 1);
        p *= x;
        q *= y;
        return r + p / q;
    }
}
int main()
{
    cout << taylor(2, 5);
    return 0;
}