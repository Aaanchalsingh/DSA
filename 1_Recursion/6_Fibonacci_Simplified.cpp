// FIBONACCI SERIES
//   FIB(N)=1+1+2+3+5+8+13
//   fib(n)= fib(n-1) + fib(n-2)
// time complexity=o(n)
#include <bits/stdc++.h>
using namespace std;
int Arr[10];
int fibonacci(int x)
{
    if (x <= 1)
    {
        Arr[x] = x;
    }
    else
    {
        if (Arr[x - 1] == -1)
        {
            Arr[x - 1] = fibonacci(x - 1);
        }
        if (Arr[x - 2] == -1)
        {
            Arr[x - 2] = fibonacci(x - 2);
        }
        Arr[x] = Arr[x - 1] + Arr[x - 2];
        return Arr[x - 1] + Arr[x - 2];
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        Arr[i] = -1;
    }

    cout << fibonacci(5);
    return 0;
}