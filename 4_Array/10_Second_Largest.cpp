//#FIND SECOND LARGEST ELEMENT IN AN ARRAY
#include <bits/stdc++.h>
using namespace std;
int k = 0;
int maximum(int *A, int last, int n)
{
    if (n <= 0)
    {
        return last;
    }
    else
    {
        k = 0;
        for (int i = 0; i < 10; i++)
        {
            if ((A[i] < last) && (k < A[i]))
            {
                k = A[i];
            }
        }
        maximum(A, k, n - 1);
    }
}
int main()
{
    int A[10] = {6, 2, 1, 5, 2, 4, 8, 9, 3, 1};
    int max = A[0], last = 0;
    for (int i = 0; i < 10; i++)
    {
        if (max < A[i])
        {
            last = max;
            max = A[i];
        }
    }
    cout << maximum(A, last, 2); // FOR FOURTH LARGEST NUMBER

    return 0;
}