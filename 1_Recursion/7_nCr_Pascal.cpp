// USING RECURSIVE APPROACH// Using Pascal`s triangle
#include <bits/stdc++.h>
using namespace std;
int C(int n, int r)
{
    if ((r == 0) || (r == n))
    {
        return 1;
    }
    
    else
    {
        return C(n - 1, r - 1) + C(n - 1, r);
    }
}
int main()
{
    cout << C(4, 2);
    return 0;
}