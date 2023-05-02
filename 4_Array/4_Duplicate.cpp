//#FIND DUPLICATE ELEMENT IN AN ARRAY AND COUNT IT ALSO
//@  DUPLICATE IN SORTED ARRAY
//* DUPLICATE  IN UNSORTED ARRAY
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A[10] = {1, 2, 3, 3, 4, 5, 7, 7, 7, 8};
    int last = -1, j;
    for (int i = 0; i < 10; i++)
    {
        if ((A[i] == A[i + 1]))
        {
            j = i + 1;
            while (A[i] == A[j])
            {
                j++;
            }
            cout << A[i] << " Appears " << j - i << " times\n";
            i = j - 1;
        }
    }

    return 0;
}