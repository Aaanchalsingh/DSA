//#HASH TABLE TECHNIQUE TO FIND DUPLICATE ELEMENT IN A STRING AND COUNT IT ALSO
//$WORKS FOR BOTH SORTED AND UNSORTED
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char A[10] = "AANCHALL";
    int B[26] = {0};
    for (int i = 0; i < 10; i++)
    {
        B[A[i] - 65]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (B[i] > 1)
        {
            char p = i + 65;
            cout << p << " Appears " << B[i] << " times\n";
        }
    }
    return 0;
}
