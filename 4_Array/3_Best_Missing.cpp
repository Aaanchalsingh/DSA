//#HASH TABLE TECHNIQUE TO FIND MULTIPLE MISSING IN UNSORTED ARRAY
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[10] = {10, 4, 3, 2, 1, 12, 11, 9, 7, 6};
    int max = A[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    int *B = new int[max];
    for (int i = 0; i < max; i++)
    {
        B[i] = -1;
    }
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        n = A[i];
        B[n] = 0;
       // B[A[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        if (B[i] == -1)
            cout << i << " ";
    }
    return 0;
}
