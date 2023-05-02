// IN ALL THE QUIZ QUESTION DISPLAY THE OUTPUT OF THE PROGRAM
//&POINTS TO REMEMBER
//$SUCCESIVE DIVISON = O(logn)
//$SUCCESIVE MULTIPL = O(2^n)
//* Static Variable are not initialized everytime function is called thats the difference between them and any normal variable
#include <bits/stdc++.h>
using namespace std;
void count(int n)
{
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if (n > 1)
        count(n - 1);
    printf("%d", d); // Assign value to d during return time
}
int main()
{
    count(3);
    return 0;
    // Always make a flow like this
    //                   count(5)
    //                      |
    //   n    d    d++   count(4)    d
    //                      |
    //   n    d    d++   count(3)    d
    //                      |
    //   n    d    d++   count(2)    d
    //                      |
    //   n    d    d++   count(1)    d
    //                      |
    //               NO EXTRA CALLING
}