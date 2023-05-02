#include <bits/stdc++.h>
using namespace std;
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    else
        return pow(m * m, (n - 1) / 2) * m;
}
int main()
{
    int res = pow(2, 4);
    cout << res;
    return 0;
}