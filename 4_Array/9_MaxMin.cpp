//#FIND MAXIMUM AND MINIMUM  ELEMENT IN AN ARRAY SIMULTANEOUSLY
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[10] = {6, 2, 1, 5, 2, 4, 8, 9, 3, 1};
    int max = A[0];
    int min = A[0];
    for (int i = 0; i < 10; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
        else if (max < A[i])
        {
            max = A[i];
        }
    }
    cout << "MAX " << max << "\nMIN " << min;
    return 0;
}