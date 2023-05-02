// IN ALL THE QUIZ QUESTION DISPLAY THE OUTPUT OF THE PROGRAM
//&POINTS TO REMEMBER
#include <bits/stdc++.h>
using namespace std;
void foo(int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0)
        return;
    k = n % 10;  //#NOTE: 2%10=2
    j = n / 10;
    sum = sum + k;
    foo(j, sum);
    cout << k;
}
int main()
{
    int a = 2048, sum = 0;
    foo(a, sum);
    cout << sum;//THIS SUM IS OF MAIN FUNCTION AND BECAUSE ITS CALL BY VALUE SO IT WILL NOT BE CHANGED 
    //#foo FUNCTION ALSO HAVE HAVE A SUM VARIABLE SO DONT GET CONFUSED
}