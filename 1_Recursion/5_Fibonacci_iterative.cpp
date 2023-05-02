// FIBONACCI SERIES
//   FIB(N)=1+1+2+3+5+8+13
// time complexity=O(n)
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    int s = 1, t0 = 0, t1 = 1;
    for (int i = 1; i < n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int main()
{
    for (int i = 1; i < 10; i++)
    {
        cout << fibonacci(i) << "+";
    }

    return 0;
}