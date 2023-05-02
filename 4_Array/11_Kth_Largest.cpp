//#FIND Kth LARGEST ELEMENT IN AN ARRAY
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[10] = {6, 2, 1, 5, 2, 4, 8, 9, 3, 1};
    int max = A[0], k = 4;
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
    int i = max;
    while ((k > 0) && (i >= 0))
    {
        if (B[i] >= 1) // 0,1,2,3,4,5,6,0,8,9
        {
            k--;
        }
        i--;
    }
    cout << i + 1;

    return 0;
}
