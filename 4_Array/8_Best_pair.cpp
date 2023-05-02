// BEST WAY TO FIND PAIRS WITH SUM K
//ITS BEST WAY BECAUSE IT NEED LESS SPACE THAN HASHING
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[10] = {6, 2, 1, 5, 2, 4, 8, 9, 3, 1};
    int i, j, k = 10, pairs = 0;
    for ( i = 0; i < 9; i++)
    {
        for ( j = i + 1; j < 10; j++)
        {
            if ((A[i] + A[j]) == k)
            {
                pairs++;
                cout << A[i] << " " << A[j] << endl;
            }
        }
    }
    cout << "TOTAL PAIRS = " << pairs;
    return 0;
}