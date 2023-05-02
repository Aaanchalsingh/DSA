//IN ALL THE QUIZ QUESTION DISPLAY THE OUTPUT OF THE PROGRAM 
//&POINTS TO REMEMBER
//* Static Variable are not initialized everytime function is called thats the difference between them and any normal variable
#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    static int i = 1;//-In this program the value of i will be updated because it is static
    if (n >= 5)
        return n;
    n = n + i;
    i++;
    return f(n);
}
int main()
{
    cout<<f(1);
    return 0;
}