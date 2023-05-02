// IN ALL THE QUIZ QUESTION DISPLAY THE OUTPUT OF THE PROGRAM
//&POINTS TO REMEMBER
#include <bits/stdc++.h>
using namespace std;
int k = 0;
int f(int &x, int c)//#NOTE: HERE X IS CALL BY REFERENCE WHATEVER CHANGES WILL BE THERE IN X WILL DIRECTLY CHANGE IN P 
//@YOU SHOULD ALWAYS TREAT THIS FUNCTION AS F(X,5) NOT F(5,5)
{
    c = c - 1;
    if (c == 0)
        return 1;
    x = x + 1;
    k = f(x, c) * x;//$MULTIPLY X AT RETURNING TIME ONLY
    return k;
}
int main()
{
    int p = 5;
    cout << f(p, p);
    return 0;
}