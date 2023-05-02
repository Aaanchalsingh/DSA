// IN ALL THE QUIZ QUESTION DISPLAY THE OUTPUT OF THE PROGRAM
//&POINTS TO REMEMBER
#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    int x = 1, k;
    if (n == 1)
        return x;
    for (k = 1; k < n; ++k)          //%NOTE: NO DIFFERENCE ++K OR K++
        x = x + fun(k) * fun(n - k); //#INSTEAD OF SOLVING TREE GO FOR TABULATION METHOD BY CALCULATING fun(1) first then fun(2)
    return x;
}
int main()
{
    cout << fun(5);
    return 0;
}