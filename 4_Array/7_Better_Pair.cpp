//#HASH TABLE TECHNIQUE TO FIND PAIRS WITH SUM K
//$WORKS FOR BOTH SORTED AND UNSORTED
//@IN HASHING WE COMPROMISE WITH SPACE SO AS TO DO IN LESS TIME DUE TO CREATION OF AUXILLARY ARRAY
//* SPACE~1/TIME 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[10] = {6, 2, 1, 5, 2, 4, 8, 9, 3, 1};
    int max = A[0], k = 10, pairs = 0;
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
        int net = abs(k - A[i]);
        if (B[net] == 0)
        {
            B[A[i]]++;
        }
        else
        {
            pairs++;
            cout << A[i] << " " << net << endl;
        }
    }
    cout << "TOTAL PAIRS = " << pairs;
    return 0;
}
