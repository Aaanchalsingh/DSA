// FIBONACCI SERIES
//   FIB(N)=1+1+2+3+5+8+13
//   fib(n)= fib(n-1) + fib(n-2)
// time complexity=2^n
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int x)
{
    if (x <= 1)
    {
        return x;
    }
    else
    {
        return fibonacci(x - 1) + fibonacci(x - 2);
    }
}
int main()
{
   for (int i = 1; i < 10; i++)
    {
        cout << fibonacci(i) << "+";
    }
    return 0;
}