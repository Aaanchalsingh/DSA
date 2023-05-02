//#HASH TABLE TECHNIQUE TO FIND DUPLICATE ELEMENT IN AN ARRAY AND COUNT IT ALSO
//$WORKS FOR BOTH SORTED AND UNSORTED
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[10] = {10, 3, 2, 1, 12, 10, 10, 2, 2, 1};
    int max = A[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    int *B = new int[max];
    for (int i = 0; i <= max; i++)
    {
        B[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        B[A[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if (B[i] > 1)
            cout << i << " Appears " << B[i] << " times\n";
    }
    return 0;
}
