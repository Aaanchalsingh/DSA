#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}
int fact(int n)
{
    if (n <= 1)
        return 1;
    return fact(n - 1) * n;
}
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    return pow(m, n - 1) * m;
}
int main()
{
    cout << sum(4);
    cout << fact(4);
    cout << pow(2, 4);
    return 0;
}